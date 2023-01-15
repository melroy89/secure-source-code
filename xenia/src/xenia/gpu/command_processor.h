/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_GPU_COMMAND_PROCESSOR_H_
#define XENIA_GPU_COMMAND_PROCESSOR_H_

#include <atomic>
#include <cstring>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <vector>

#include "xenia/base/ring_buffer.h"
#include "xenia/base/threading.h"
#include "xenia/gpu/register_file.h"
#include "xenia/gpu/registers.h"
#include "xenia/gpu/trace_writer.h"
#include "xenia/gpu/xenos.h"
#include "xenia/kernel/xthread.h"
#include "xenia/memory.h"
#include "xenia/ui/presenter.h"

namespace xe {

class ByteStream;

namespace gpu {

class GraphicsSystem;
class Shader;

struct SwapState {
  // Lock must be held when changing data in this structure.
  std::mutex mutex;
  // Dimensions of the framebuffer textures. Should match window size.
  uint32_t width = 0;
  uint32_t height = 0;
  // Current front buffer, being drawn to the screen.
  uintptr_t front_buffer_texture = 0;
  // Current back buffer, being updated by the CP.
  uintptr_t back_buffer_texture = 0;
  // Backend data
  void* backend_data = nullptr;
  // Whether the back buffer is dirty and a swap is pending.
  bool pending = false;
};

enum class SwapMode {
  kNormal,
  kIgnored,
};

enum class GammaRampType {
  kUnknown = 0,
  kTable,
  kPWL,
};

class CommandProcessor {
 public:
  enum class SwapPostEffect {
    kNone,
    kFxaa,
    kFxaaExtreme,
  };

  CommandProcessor(GraphicsSystem* graphics_system,
                   kernel::KernelState* kernel_state);
  virtual ~CommandProcessor();

  uint32_t counter() const { return counter_; }
  void increment_counter() { counter_++; }

  Shader* active_vertex_shader() const { return active_vertex_shader_; }
  Shader* active_pixel_shader() const { return active_pixel_shader_; }

  virtual bool Initialize();
  virtual void Shutdown();

  void CallInThread(std::function<void()> fn);

  virtual void ClearCaches();

  // "Desired" is for the external thread managing the post-processing effect.
  SwapPostEffect GetDesiredSwapPostEffect() const {
    return swap_post_effect_desired_;
  }
  void SetDesiredSwapPostEffect(SwapPostEffect swap_post_effect);
  // Implementations must not make assumptions that the front buffer will
  // necessarily be a resolve destination - it may be a texture generated by any
  // means like written to by the CPU or loaded from a file (the disclaimer
  // screen right in the beginning of 4D530AA4 is not a resolved render target,
  // for instance).
  virtual void IssueSwap(uint32_t frontbuffer_ptr, uint32_t frontbuffer_width,
                         uint32_t frontbuffer_height) = 0;

  // May be called not only from the command processor thread when the command
  // processor is paused, and the termination of this function may be explicitly
  // awaited.
  virtual void InitializeShaderStorage(const std::filesystem::path& cache_root,
                                       uint32_t title_id, bool blocking);

  virtual void RequestFrameTrace(const std::filesystem::path& root_path);
  virtual void BeginTracing(const std::filesystem::path& root_path);
  virtual void EndTracing();

  virtual void TracePlaybackWroteMemory(uint32_t base_ptr, uint32_t length) = 0;

  void RestoreRegisters(uint32_t first_register,
                        const uint32_t* register_values,
                        uint32_t register_count, bool execute_callbacks);
  void RestoreGammaRamp(
      const reg::DC_LUT_30_COLOR* new_gamma_ramp_256_entry_table,
      const reg::DC_LUT_PWL_DATA* new_gamma_ramp_pwl_rgb,
      uint32_t new_gamma_ramp_rw_component);
  virtual void RestoreEdramSnapshot(const void* snapshot) = 0;

  void InitializeRingBuffer(uint32_t ptr, uint32_t size_log2);
  void EnableReadPointerWriteBack(uint32_t ptr, uint32_t block_size_log2);

  void UpdateWritePointer(uint32_t value);

  void ExecutePacket(uint32_t ptr, uint32_t count);

  bool is_paused() const { return paused_; }
  void Pause();
  void Resume();

  bool Save(ByteStream* stream);
  bool Restore(ByteStream* stream);

 protected:
  struct IndexBufferInfo {
    xenos::IndexFormat format = xenos::IndexFormat::kInt16;
    xenos::Endian endianness = xenos::Endian::kNone;
    uint32_t count = 0;
    uint32_t guest_base = 0;
    size_t length = 0;
  };

  void WorkerThreadMain();
  virtual bool SetupContext() = 0;
  virtual void ShutdownContext() = 0;

  virtual void WriteRegister(uint32_t index, uint32_t value);

  const reg::DC_LUT_30_COLOR* gamma_ramp_256_entry_table() const {
    return gamma_ramp_256_entry_table_;
  }
  const reg::DC_LUT_PWL_DATA* gamma_ramp_pwl_rgb() const {
    return gamma_ramp_pwl_rgb_[0];
  }
  virtual void OnGammaRamp256EntryTableValueWritten() {}
  virtual void OnGammaRampPWLValueWritten() {}

  virtual void MakeCoherent();
  virtual void PrepareForWait();
  virtual void ReturnFromWait();

  uint32_t ExecutePrimaryBuffer(uint32_t start_index, uint32_t end_index);
  virtual void OnPrimaryBufferEnd() {}
  void ExecuteIndirectBuffer(uint32_t ptr, uint32_t length);
  bool ExecutePacket(RingBuffer* reader);
  bool ExecutePacketType0(RingBuffer* reader, uint32_t packet);
  bool ExecutePacketType1(RingBuffer* reader, uint32_t packet);
  bool ExecutePacketType2(RingBuffer* reader, uint32_t packet);
  bool ExecutePacketType3(RingBuffer* reader, uint32_t packet);
  bool ExecutePacketType3_ME_INIT(RingBuffer* reader, uint32_t packet,
                                  uint32_t count);
  bool ExecutePacketType3_NOP(RingBuffer* reader, uint32_t packet,
                              uint32_t count);
  bool ExecutePacketType3_INTERRUPT(RingBuffer* reader, uint32_t packet,
                                    uint32_t count);
  bool ExecutePacketType3_XE_SWAP(RingBuffer* reader, uint32_t packet,
                                  uint32_t count);
  bool ExecutePacketType3_INDIRECT_BUFFER(RingBuffer* reader, uint32_t packet,
                                          uint32_t count);
  bool ExecutePacketType3_WAIT_REG_MEM(RingBuffer* reader, uint32_t packet,
                                       uint32_t count);
  bool ExecutePacketType3_REG_RMW(RingBuffer* reader, uint32_t packet,
                                  uint32_t count);
  bool ExecutePacketType3_REG_TO_MEM(RingBuffer* reader, uint32_t packet,
                                     uint32_t count);
  bool ExecutePacketType3_MEM_WRITE(RingBuffer* reader, uint32_t packet,
                                    uint32_t count);
  bool ExecutePacketType3_COND_WRITE(RingBuffer* reader, uint32_t packet,
                                     uint32_t count);
  bool ExecutePacketType3_EVENT_WRITE(RingBuffer* reader, uint32_t packet,
                                      uint32_t count);
  bool ExecutePacketType3_EVENT_WRITE_SHD(RingBuffer* reader, uint32_t packet,
                                          uint32_t count);
  bool ExecutePacketType3_EVENT_WRITE_EXT(RingBuffer* reader, uint32_t packet,
                                          uint32_t count);
  bool ExecutePacketType3_EVENT_WRITE_ZPD(RingBuffer* reader, uint32_t packet,
                                          uint32_t count);
  bool ExecutePacketType3Draw(RingBuffer* reader, uint32_t packet,
                              const char* opcode_name,
                              uint32_t viz_query_condition,
                              uint32_t count_remaining);
  bool ExecutePacketType3_DRAW_INDX(RingBuffer* reader, uint32_t packet,
                                    uint32_t count);
  bool ExecutePacketType3_DRAW_INDX_2(RingBuffer* reader, uint32_t packet,
                                      uint32_t count);
  bool ExecutePacketType3_SET_CONSTANT(RingBuffer* reader, uint32_t packet,
                                       uint32_t count);
  bool ExecutePacketType3_SET_CONSTANT2(RingBuffer* reader, uint32_t packet,
                                        uint32_t count);
  bool ExecutePacketType3_LOAD_ALU_CONSTANT(RingBuffer* reader, uint32_t packet,
                                            uint32_t count);
  bool ExecutePacketType3_SET_SHADER_CONSTANTS(RingBuffer* reader,
                                               uint32_t packet, uint32_t count);
  bool ExecutePacketType3_IM_LOAD(RingBuffer* reader, uint32_t packet,
                                  uint32_t count);
  bool ExecutePacketType3_IM_LOAD_IMMEDIATE(RingBuffer* reader,

                                            uint32_t packet, uint32_t count);
  bool ExecutePacketType3_INVALIDATE_STATE(RingBuffer* reader, uint32_t packet,
                                           uint32_t count);
  bool ExecutePacketType3_VIZ_QUERY(RingBuffer* reader, uint32_t packet,
                                    uint32_t count);

  virtual Shader* LoadShader(xenos::ShaderType shader_type,
                             uint32_t guest_address,
                             const uint32_t* host_address,
                             uint32_t dword_count) = 0;

  virtual bool IssueDraw(xenos::PrimitiveType prim_type, uint32_t index_count,
                         IndexBufferInfo* index_buffer_info,
                         bool major_mode_explicit) = 0;
  virtual bool IssueCopy() = 0;

  // "Actual" is for the command processor thread, to be read by the
  // implementations.
  SwapPostEffect GetActualSwapPostEffect() const {
    return swap_post_effect_actual_;
  }

  virtual void InitializeTrace();

  Memory* memory_ = nullptr;
  kernel::KernelState* kernel_state_ = nullptr;
  GraphicsSystem* graphics_system_ = nullptr;
  RegisterFile* register_file_ = nullptr;

  TraceWriter trace_writer_;
  enum class TraceState {
    kDisabled,
    kStreaming,
    kSingleFrame,
  };
  TraceState trace_state_ = TraceState::kDisabled;
  std::filesystem::path trace_stream_path_;
  std::filesystem::path trace_frame_path_;

  std::atomic<bool> worker_running_;
  kernel::object_ref<kernel::XHostThread> worker_thread_;

  std::queue<std::function<void()>> pending_fns_;

  // MicroEngine binary from PM4_ME_INIT
  std::vector<uint32_t> me_bin_;

  uint32_t counter_ = 0;

  uint32_t primary_buffer_ptr_ = 0;
  uint32_t primary_buffer_size_ = 0;

  uint32_t read_ptr_index_ = 0;
  uint32_t read_ptr_update_freq_ = 0;
  uint32_t read_ptr_writeback_ptr_ = 0;

  std::unique_ptr<xe::threading::Event> write_ptr_index_event_;
  std::atomic<uint32_t> write_ptr_index_;

  uint64_t bin_select_ = 0xFFFFFFFFull;
  uint64_t bin_mask_ = 0xFFFFFFFFull;

  Shader* active_vertex_shader_ = nullptr;
  Shader* active_pixel_shader_ = nullptr;

  bool paused_ = false;

  // By default (such as for tools), post-processing is disabled.
  // "Desired" is for the external thread managing the post-processing effect.
  SwapPostEffect swap_post_effect_desired_ = SwapPostEffect::kNone;
  SwapPostEffect swap_post_effect_actual_ = SwapPostEffect::kNone;

 private:
  reg::DC_LUT_30_COLOR gamma_ramp_256_entry_table_[256] = {};
  reg::DC_LUT_PWL_DATA gamma_ramp_pwl_rgb_[128][3] = {};
  uint32_t gamma_ramp_rw_component_ = 0;
};

}  // namespace gpu
}  // namespace xe

#endif  // XENIA_GPU_COMMAND_PROCESSOR_H_