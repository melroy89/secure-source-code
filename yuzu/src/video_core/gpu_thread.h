// SPDX-FileCopyrightText: Copyright 2019 yuzu Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <optional>
#include <thread>
#include <variant>

#include "common/polyfill_thread.h"
#include "common/threadsafe_queue.h"
#include "video_core/framebuffer_config.h"

namespace Tegra {
struct FramebufferConfig;
namespace Control {
class Scheduler;
}
} // namespace Tegra

namespace Core {
namespace Frontend {
class GraphicsContext;
}
class System;
} // namespace Core

namespace VideoCore {
class RasterizerInterface;
class RendererBase;
} // namespace VideoCore

namespace VideoCommon::GPUThread {

/// Command to signal to the GPU thread that a command list is ready for processing
struct SubmitListCommand final {
    explicit SubmitListCommand(s32 channel_, Tegra::CommandList&& entries_)
        : channel{channel_}, entries{std::move(entries_)} {}

    s32 channel;
    Tegra::CommandList entries;
};

/// Command to signal to the GPU thread that a swap buffers is pending
struct SwapBuffersCommand final {
    explicit SwapBuffersCommand(std::optional<const Tegra::FramebufferConfig> framebuffer_)
        : framebuffer{std::move(framebuffer_)} {}

    std::optional<Tegra::FramebufferConfig> framebuffer;
};

/// Command to signal to the GPU thread to flush a region
struct FlushRegionCommand final {
    explicit constexpr FlushRegionCommand(VAddr addr_, u64 size_) : addr{addr_}, size{size_} {}

    VAddr addr;
    u64 size;
};

/// Command to signal to the GPU thread to invalidate a region
struct InvalidateRegionCommand final {
    explicit constexpr InvalidateRegionCommand(VAddr addr_, u64 size_) : addr{addr_}, size{size_} {}

    VAddr addr;
    u64 size;
};

/// Command to signal to the GPU thread to flush and invalidate a region
struct FlushAndInvalidateRegionCommand final {
    explicit constexpr FlushAndInvalidateRegionCommand(VAddr addr_, u64 size_)
        : addr{addr_}, size{size_} {}

    VAddr addr;
    u64 size;
};

/// Command called within the gpu, to schedule actions after a command list end
struct OnCommandListEndCommand final {};

/// Command to make the gpu look into pending requests
struct GPUTickCommand final {};

using CommandData =
    std::variant<std::monostate, SubmitListCommand, SwapBuffersCommand, FlushRegionCommand,
                 InvalidateRegionCommand, FlushAndInvalidateRegionCommand, OnCommandListEndCommand,
                 GPUTickCommand>;

struct CommandDataContainer {
    CommandDataContainer() = default;

    explicit CommandDataContainer(CommandData&& data_, u64 next_fence_, bool block_)
        : data{std::move(data_)}, fence{next_fence_}, block(block_) {}

    CommandData data;
    u64 fence{};
    bool block{};
};

/// Struct used to synchronize the GPU thread
struct SynchState final {
    using CommandQueue = Common::MPSCQueue<CommandDataContainer, true>;
    std::mutex write_lock;
    CommandQueue queue;
    u64 last_fence{};
    std::atomic<u64> signaled_fence{};
    std::condition_variable_any cv;
};

/// Class used to manage the GPU thread
class ThreadManager final {
public:
    explicit ThreadManager(Core::System& system_, bool is_async_);
    ~ThreadManager();

    /// Creates and starts the GPU thread.
    void StartThread(VideoCore::RendererBase& renderer, Core::Frontend::GraphicsContext& context,
                     Tegra::Control::Scheduler& scheduler);

    /// Push GPU command entries to be processed
    void SubmitList(s32 channel, Tegra::CommandList&& entries);

    /// Swap buffers (render frame)
    void SwapBuffers(const Tegra::FramebufferConfig* framebuffer);

    /// Notify rasterizer that any caches of the specified region should be flushed to Switch memory
    void FlushRegion(VAddr addr, u64 size);

    /// Notify rasterizer that any caches of the specified region should be invalidated
    void InvalidateRegion(VAddr addr, u64 size);

    /// Notify rasterizer that any caches of the specified region should be flushed and invalidated
    void FlushAndInvalidateRegion(VAddr addr, u64 size);

    void OnCommandListEnd();

    void TickGPU();

private:
    /// Pushes a command to be executed by the GPU thread
    u64 PushCommand(CommandData&& command_data, bool block = false);

    Core::System& system;
    const bool is_async;
    VideoCore::RasterizerInterface* rasterizer = nullptr;

    SynchState state;
    std::jthread thread;
};

} // namespace VideoCommon::GPUThread