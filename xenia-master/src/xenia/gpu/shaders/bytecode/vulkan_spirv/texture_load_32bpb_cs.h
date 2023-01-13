// Generated with `xb buildshaders`.
#if 0
; SPIR-V
; Version: 1.0
; Generator: Khronos Glslang Reference Front End; 10
; Bound: 25059
; Schema: 0
               OpCapability Shader
          %1 = OpExtInstImport "GLSL.std.450"
               OpMemoryModel Logical GLSL450
               OpEntryPoint GLCompute %5663 "main" %gl_GlobalInvocationID
               OpExecutionMode %5663 LocalSize 4 32 1
               OpMemberDecorate %_struct_1161 0 Offset 0
               OpMemberDecorate %_struct_1161 1 Offset 4
               OpMemberDecorate %_struct_1161 2 Offset 8
               OpMemberDecorate %_struct_1161 3 Offset 12
               OpMemberDecorate %_struct_1161 4 Offset 16
               OpMemberDecorate %_struct_1161 5 Offset 28
               OpMemberDecorate %_struct_1161 6 Offset 32
               OpMemberDecorate %_struct_1161 7 Offset 36
               OpDecorate %_struct_1161 Block
               OpDecorate %5245 DescriptorSet 2
               OpDecorate %5245 Binding 0
               OpDecorate %gl_GlobalInvocationID BuiltIn GlobalInvocationId
               OpDecorate %_runtimearr_v4uint ArrayStride 16
               OpMemberDecorate %_struct_1972 0 NonWritable
               OpMemberDecorate %_struct_1972 0 Offset 0
               OpDecorate %_struct_1972 BufferBlock
               OpDecorate %4218 DescriptorSet 1
               OpDecorate %4218 Binding 0
               OpDecorate %_runtimearr_v4uint_0 ArrayStride 16
               OpMemberDecorate %_struct_1973 0 NonReadable
               OpMemberDecorate %_struct_1973 0 Offset 0
               OpDecorate %_struct_1973 BufferBlock
               OpDecorate %5134 DescriptorSet 0
               OpDecorate %5134 Binding 0
               OpDecorate %gl_WorkGroupSize BuiltIn WorkgroupSize
       %void = OpTypeVoid
       %1282 = OpTypeFunction %void
       %uint = OpTypeInt 32 0
     %v4uint = OpTypeVector %uint 4
        %int = OpTypeInt 32 1
      %v2int = OpTypeVector %int 2
      %v3int = OpTypeVector %int 3
       %bool = OpTypeBool
     %v2uint = OpTypeVector %uint 2
     %v3uint = OpTypeVector %uint 3
     %uint_1 = OpConstant %uint 1
     %uint_2 = OpConstant %uint 2
%uint_16711935 = OpConstant %uint 16711935
     %uint_8 = OpConstant %uint 8
%uint_4278255360 = OpConstant %uint 4278255360
     %uint_3 = OpConstant %uint 3
    %uint_16 = OpConstant %uint 16
     %uint_0 = OpConstant %uint 0
      %int_5 = OpConstant %int 5
     %uint_5 = OpConstant %uint 5
      %int_7 = OpConstant %int 7
     %int_14 = OpConstant %int 14
      %int_2 = OpConstant %int 2
    %int_n16 = OpConstant %int -16
      %int_1 = OpConstant %int 1
     %int_15 = OpConstant %int 15
      %int_4 = OpConstant %int 4
   %int_n512 = OpConstant %int -512
      %int_3 = OpConstant %int 3
     %int_16 = OpConstant %int 16
    %int_448 = OpConstant %int 448
      %int_8 = OpConstant %int 8
      %int_6 = OpConstant %int 6
     %int_63 = OpConstant %int 63
     %uint_4 = OpConstant %uint 4
%int_268435455 = OpConstant %int 268435455
     %int_n2 = OpConstant %int -2
    %uint_32 = OpConstant %uint 32
%_struct_1161 = OpTypeStruct %uint %uint %uint %uint %v3uint %uint %uint %uint
%_ptr_Uniform__struct_1161 = OpTypePointer Uniform %_struct_1161
       %5245 = OpVariable %_ptr_Uniform__struct_1161 Uniform
      %int_0 = OpConstant %int 0
%_ptr_Uniform_uint = OpTypePointer Uniform %uint
%_ptr_Uniform_v3uint = OpTypePointer Uniform %v3uint
%_ptr_Input_v3uint = OpTypePointer Input %v3uint
%gl_GlobalInvocationID = OpVariable %_ptr_Input_v3uint Input
       %2603 = OpConstantComposite %v3uint %uint_3 %uint_0 %uint_0
     %v2bool = OpTypeVector %bool 2
%_runtimearr_v4uint = OpTypeRuntimeArray %v4uint
%_struct_1972 = OpTypeStruct %_runtimearr_v4uint
%_ptr_Uniform__struct_1972 = OpTypePointer Uniform %_struct_1972
       %4218 = OpVariable %_ptr_Uniform__struct_1972 Uniform
%_ptr_Uniform_v4uint = OpTypePointer Uniform %v4uint
%_runtimearr_v4uint_0 = OpTypeRuntimeArray %v4uint
%_struct_1973 = OpTypeStruct %_runtimearr_v4uint_0
%_ptr_Uniform__struct_1973 = OpTypePointer Uniform %_struct_1973
       %5134 = OpVariable %_ptr_Uniform__struct_1973 Uniform
%gl_WorkGroupSize = OpConstantComposite %v3uint %uint_4 %uint_32 %uint_1
     %uint_9 = OpConstant %uint 9
       %2510 = OpConstantComposite %v4uint %uint_16711935 %uint_16711935 %uint_16711935 %uint_16711935
        %317 = OpConstantComposite %v4uint %uint_8 %uint_8 %uint_8 %uint_8
       %1838 = OpConstantComposite %v4uint %uint_4278255360 %uint_4278255360 %uint_4278255360 %uint_4278255360
        %749 = OpConstantComposite %v4uint %uint_16 %uint_16 %uint_16 %uint_16
       %5663 = OpFunction %void None %1282
      %15110 = OpLabel
               OpSelectionMerge %19578 None
               OpSwitch %uint_0 %11880
      %11880 = OpLabel
      %24791 = OpAccessChain %_ptr_Uniform_uint %5245 %int_0
      %13606 = OpLoad %uint %24791
      %24540 = OpBitwiseAnd %uint %13606 %uint_1
      %17270 = OpINotEqual %bool %24540 %uint_0
      %12328 = OpBitwiseAnd %uint %13606 %uint_2
      %17284 = OpINotEqual %bool %12328 %uint_0
       %7856 = OpShiftRightLogical %uint %13606 %uint_2
      %25058 = OpBitwiseAnd %uint %7856 %uint_3
      %18732 = OpAccessChain %_ptr_Uniform_uint %5245 %int_1
      %24236 = OpLoad %uint %18732
      %20154 = OpAccessChain %_ptr_Uniform_uint %5245 %int_2
      %22408 = OpLoad %uint %20154
      %20155 = OpAccessChain %_ptr_Uniform_uint %5245 %int_3
      %22409 = OpLoad %uint %20155
      %20156 = OpAccessChain %_ptr_Uniform_v3uint %5245 %int_4
      %22410 = OpLoad %v3uint %20156
      %20157 = OpAccessChain %_ptr_Uniform_uint %5245 %int_5
      %22411 = OpLoad %uint %20157
      %20078 = OpAccessChain %_ptr_Uniform_uint %5245 %int_6
       %6594 = OpLoad %uint %20078
      %10766 = OpLoad %v3uint %gl_GlobalInvocationID
      %21387 = OpShiftLeftLogical %v3uint %10766 %2603
      %17136 = OpVectorShuffle %v2uint %21387 %21387 0 1
       %9263 = OpVectorShuffle %v2uint %22410 %22410 0 1
      %17032 = OpUGreaterThanEqual %v2bool %17136 %9263
      %24679 = OpAny %bool %17032
               OpSelectionMerge %6586 DontFlatten
               OpBranchConditional %24679 %21992 %6586
      %21992 = OpLabel
               OpBranch %19578
       %6586 = OpLabel
      %23478 = OpBitcast %v3int %21387
      %18710 = OpCompositeExtract %uint %22410 1
      %23531 = OpCompositeExtract %int %23478 0
      %22810 = OpIMul %int %23531 %int_4
       %6362 = OpCompositeExtract %int %23478 2
      %14505 = OpBitcast %int %18710
      %11279 = OpIMul %int %6362 %14505
      %17598 = OpCompositeExtract %int %23478 1
      %22228 = OpIAdd %int %11279 %17598
      %22405 = OpBitcast %int %6594
      %24535 = OpIMul %int %22228 %22405
       %8258 = OpIAdd %int %22810 %24535
      %10898 = OpBitcast %uint %8258
      %10084 = OpIAdd %uint %10898 %22411
      %21685 = OpShiftRightLogical %uint %10084 %uint_4
               OpSelectionMerge %24387 DontFlatten
               OpBranchConditional %17270 %22376 %20978
      %22376 = OpLabel
               OpSelectionMerge %7691 DontFlatten
               OpBranchConditional %17284 %11256 %6361
      %11256 = OpLabel
      %12979 = OpShiftRightArithmetic %int %17598 %int_4
      %24606 = OpShiftRightArithmetic %int %6362 %int_2
      %18759 = OpShiftRightLogical %uint %22409 %uint_4
       %6314 = OpBitcast %int %18759
      %21281 = OpIMul %int %24606 %6314
      %15143 = OpIAdd %int %12979 %21281
       %9032 = OpShiftRightLogical %uint %22408 %uint_5
      %14593 = OpBitcast %int %9032
       %8436 = OpIMul %int %15143 %14593
      %12986 = OpShiftRightArithmetic %int %23531 %int_5
      %24558 = OpIAdd %int %12986 %8436
       %8797 = OpShiftLeftLogical %int %24558 %uint_8
      %11510 = OpBitwiseAnd %int %8797 %int_268435455
      %18938 = OpShiftLeftLogical %int %11510 %int_1
      %19768 = OpBitwiseAnd %int %23531 %int_7
      %12600 = OpBitwiseAnd %int %17598 %int_6
      %17741 = OpShiftLeftLogical %int %12600 %int_2
      %17227 = OpIAdd %int %19768 %17741
       %7048 = OpShiftLeftLogical %int %17227 %uint_8
      %24035 = OpShiftRightArithmetic %int %7048 %int_6
       %8725 = OpShiftRightArithmetic %int %17598 %int_3
      %13731 = OpIAdd %int %8725 %24606
      %23052 = OpBitwiseAnd %int %13731 %int_1
      %16658 = OpShiftRightArithmetic %int %23531 %int_3
      %18794 = OpShiftLeftLogical %int %23052 %int_1
      %13501 = OpIAdd %int %16658 %18794
      %19165 = OpBitwiseAnd %int %13501 %int_3
      %21578 = OpShiftLeftLogical %int %19165 %int_1
      %15435 = OpIAdd %int %23052 %21578
      %13150 = OpBitwiseAnd %int %24035 %int_n16
      %20336 = OpIAdd %int %18938 %13150
      %23345 = OpShiftLeftLogical %int %20336 %int_1
      %23274 = OpBitwiseAnd %int %24035 %int_15
      %10332 = OpIAdd %int %23345 %23274
      %18356 = OpBitwiseAnd %int %6362 %int_3
      %21579 = OpShiftLeftLogical %int %18356 %uint_8
      %16727 = OpIAdd %int %10332 %21579
      %19166 = OpBitwiseAnd %int %17598 %int_1
      %21580 = OpShiftLeftLogical %int %19166 %int_4
      %16728 = OpIAdd %int %16727 %21580
      %20438 = OpBitwiseAnd %int %15435 %int_1
       %9987 = OpShiftLeftLogical %int %20438 %int_3
      %13106 = OpShiftRightArithmetic %int %16728 %int_6
      %14038 = OpBitwiseAnd %int %13106 %int_7
      %13330 = OpIAdd %int %9987 %14038
      %23346 = OpShiftLeftLogical %int %13330 %int_3
      %23217 = OpBitwiseAnd %int %15435 %int_n2
      %10908 = OpIAdd %int %23346 %23217
      %23347 = OpShiftLeftLogical %int %10908 %int_2
      %23218 = OpBitwiseAnd %int %16728 %int_n512
      %10909 = OpIAdd %int %23347 %23218
      %23348 = OpShiftLeftLogical %int %10909 %int_3
      %24224 = OpBitwiseAnd %int %16728 %int_63
      %21741 = OpIAdd %int %23348 %24224
               OpBranch %7691
       %6361 = OpLabel
       %6573 = OpBitcast %v2int %17136
      %17090 = OpCompositeExtract %int %6573 0
       %9469 = OpShiftRightArithmetic %int %17090 %int_5
      %10055 = OpCompositeExtract %int %6573 1
      %16476 = OpShiftRightArithmetic %int %10055 %int_5
      %23373 = OpShiftRightLogical %uint %22408 %uint_5
       %6315 = OpBitcast %int %23373
      %21319 = OpIMul %int %16476 %6315
      %16222 = OpIAdd %int %9469 %21319
      %19086 = OpShiftLeftLogical %int %16222 %uint_9
      %10934 = OpBitwiseAnd %int %17090 %int_7
      %12601 = OpBitwiseAnd %int %10055 %int_14
      %17742 = OpShiftLeftLogical %int %12601 %int_2
      %17303 = OpIAdd %int %10934 %17742
       %6375 = OpShiftLeftLogical %int %17303 %uint_2
      %10161 = OpBitwiseAnd %int %6375 %int_n16
      %12150 = OpShiftLeftLogical %int %10161 %int_1
      %15436 = OpIAdd %int %19086 %12150
      %13207 = OpBitwiseAnd %int %6375 %int_15
      %19760 = OpIAdd %int %15436 %13207
      %18357 = OpBitwiseAnd %int %10055 %int_1
      %21581 = OpShiftLeftLogical %int %18357 %int_4
      %16729 = OpIAdd %int %19760 %21581
      %20514 = OpBitwiseAnd %int %16729 %int_n512
       %9238 = OpShiftLeftLogical %int %20514 %int_3
      %18995 = OpBitwiseAnd %int %10055 %int_16
      %12151 = OpShiftLeftLogical %int %18995 %int_7
      %16730 = OpIAdd %int %9238 %12151
      %19167 = OpBitwiseAnd %int %16729 %int_448
      %21582 = OpShiftLeftLogical %int %19167 %int_2
      %16708 = OpIAdd %int %16730 %21582
      %20611 = OpBitwiseAnd %int %10055 %int_8
      %16831 = OpShiftRightArithmetic %int %20611 %int_2
       %7916 = OpShiftRightArithmetic %int %17090 %int_3
      %13750 = OpIAdd %int %16831 %7916
      %21587 = OpBitwiseAnd %int %13750 %int_3
      %21583 = OpShiftLeftLogical %int %21587 %int_6
      %15437 = OpIAdd %int %16708 %21583
      %14157 = OpBitwiseAnd %int %16729 %int_63
      %12098 = OpIAdd %int %15437 %14157
               OpBranch %7691
       %7691 = OpLabel
      %10540 = OpPhi %int %21741 %11256 %12098 %6361
               OpBranch %24387
      %20978 = OpLabel
      %15548 = OpBitcast %int %22409
      %24760 = OpIMul %int %6362 %15548
       %8334 = OpIAdd %int %24760 %17598
       %8952 = OpBitcast %int %22408
       %7839 = OpIMul %int %8334 %8952
       %7984 = OpIAdd %int %22810 %7839
               OpBranch %24387
      %24387 = OpLabel
      %10814 = OpPhi %int %10540 %7691 %7984 %20978
       %6719 = OpBitcast %int %24236
      %22221 = OpIAdd %int %6719 %10814
      %16105 = OpBitcast %uint %22221
      %22117 = OpShiftRightLogical %uint %16105 %uint_4
      %17173 = OpAccessChain %_ptr_Uniform_v4uint %4218 %int_0 %22117
       %7338 = OpLoad %v4uint %17173
      %13760 = OpIEqual %bool %25058 %uint_1
      %21366 = OpIEqual %bool %25058 %uint_2
      %22150 = OpLogicalOr %bool %13760 %21366
               OpSelectionMerge %13411 None
               OpBranchConditional %22150 %10583 %13411
      %10583 = OpLabel
      %18271 = OpBitwiseAnd %v4uint %7338 %2510
       %9425 = OpShiftLeftLogical %v4uint %18271 %317
      %20652 = OpBitwiseAnd %v4uint %7338 %1838
      %17549 = OpShiftRightLogical %v4uint %20652 %317
      %16376 = OpBitwiseOr %v4uint %9425 %17549
               OpBranch %13411
      %13411 = OpLabel
      %22649 = OpPhi %v4uint %7338 %24387 %16376 %10583
      %19638 = OpIEqual %bool %25058 %uint_3
      %15139 = OpLogicalOr %bool %21366 %19638
               OpSelectionMerge %11416 None
               OpBranchConditional %15139 %11064 %11416
      %11064 = OpLabel
      %24087 = OpShiftLeftLogical %v4uint %22649 %749
      %15335 = OpShiftRightLogical %v4uint %22649 %749
      %10728 = OpBitwiseOr %v4uint %24087 %15335
               OpBranch %11416
      %11416 = OpLabel
      %19767 = OpPhi %v4uint %22649 %13411 %10728 %11064
      %24825 = OpAccessChain %_ptr_Uniform_v4uint %5134 %int_0 %21685
               OpStore %24825 %19767
      %15044 = OpIAdd %uint %21685 %int_1
      %18776 = OpSelect %uint %17270 %uint_32 %uint_16
      %11803 = OpShiftRightLogical %uint %18776 %uint_4
      %13947 = OpIAdd %uint %22117 %11803
      %22298 = OpAccessChain %_ptr_Uniform_v4uint %4218 %int_0 %13947
       %6578 = OpLoad %v4uint %22298
               OpSelectionMerge %14874 None
               OpBranchConditional %22150 %10584 %14874
      %10584 = OpLabel
      %18272 = OpBitwiseAnd %v4uint %6578 %2510
       %9426 = OpShiftLeftLogical %v4uint %18272 %317
      %20653 = OpBitwiseAnd %v4uint %6578 %1838
      %17550 = OpShiftRightLogical %v4uint %20653 %317
      %16377 = OpBitwiseOr %v4uint %9426 %17550
               OpBranch %14874
      %14874 = OpLabel
      %10924 = OpPhi %v4uint %6578 %11416 %16377 %10584
               OpSelectionMerge %11417 None
               OpBranchConditional %15139 %11065 %11417
      %11065 = OpLabel
      %24088 = OpShiftLeftLogical %v4uint %10924 %749
      %15336 = OpShiftRightLogical %v4uint %10924 %749
      %10729 = OpBitwiseOr %v4uint %24088 %15336
               OpBranch %11417
      %11417 = OpLabel
      %19769 = OpPhi %v4uint %10924 %14874 %10729 %11065
       %8053 = OpAccessChain %_ptr_Uniform_v4uint %5134 %int_0 %15044
               OpStore %8053 %19769
               OpBranch %19578
      %19578 = OpLabel
               OpReturn
               OpFunctionEnd
#endif

const uint32_t texture_load_32bpb_cs[] = {
    0x07230203, 0x00010000, 0x0008000A, 0x000061E3, 0x00000000, 0x00020011,
    0x00000001, 0x0006000B, 0x00000001, 0x4C534C47, 0x6474732E, 0x3035342E,
    0x00000000, 0x0003000E, 0x00000000, 0x00000001, 0x0006000F, 0x00000005,
    0x0000161F, 0x6E69616D, 0x00000000, 0x00000F48, 0x00060010, 0x0000161F,
    0x00000011, 0x00000004, 0x00000020, 0x00000001, 0x00050048, 0x00000489,
    0x00000000, 0x00000023, 0x00000000, 0x00050048, 0x00000489, 0x00000001,
    0x00000023, 0x00000004, 0x00050048, 0x00000489, 0x00000002, 0x00000023,
    0x00000008, 0x00050048, 0x00000489, 0x00000003, 0x00000023, 0x0000000C,
    0x00050048, 0x00000489, 0x00000004, 0x00000023, 0x00000010, 0x00050048,
    0x00000489, 0x00000005, 0x00000023, 0x0000001C, 0x00050048, 0x00000489,
    0x00000006, 0x00000023, 0x00000020, 0x00050048, 0x00000489, 0x00000007,
    0x00000023, 0x00000024, 0x00030047, 0x00000489, 0x00000002, 0x00040047,
    0x0000147D, 0x00000022, 0x00000002, 0x00040047, 0x0000147D, 0x00000021,
    0x00000000, 0x00040047, 0x00000F48, 0x0000000B, 0x0000001C, 0x00040047,
    0x000007DC, 0x00000006, 0x00000010, 0x00040048, 0x000007B4, 0x00000000,
    0x00000018, 0x00050048, 0x000007B4, 0x00000000, 0x00000023, 0x00000000,
    0x00030047, 0x000007B4, 0x00000003, 0x00040047, 0x0000107A, 0x00000022,
    0x00000001, 0x00040047, 0x0000107A, 0x00000021, 0x00000000, 0x00040047,
    0x000007DD, 0x00000006, 0x00000010, 0x00040048, 0x000007B5, 0x00000000,
    0x00000019, 0x00050048, 0x000007B5, 0x00000000, 0x00000023, 0x00000000,
    0x00030047, 0x000007B5, 0x00000003, 0x00040047, 0x0000140E, 0x00000022,
    0x00000000, 0x00040047, 0x0000140E, 0x00000021, 0x00000000, 0x00040047,
    0x00000BC3, 0x0000000B, 0x00000019, 0x00020013, 0x00000008, 0x00030021,
    0x00000502, 0x00000008, 0x00040015, 0x0000000B, 0x00000020, 0x00000000,
    0x00040017, 0x00000017, 0x0000000B, 0x00000004, 0x00040015, 0x0000000C,
    0x00000020, 0x00000001, 0x00040017, 0x00000012, 0x0000000C, 0x00000002,
    0x00040017, 0x00000016, 0x0000000C, 0x00000003, 0x00020014, 0x00000009,
    0x00040017, 0x00000011, 0x0000000B, 0x00000002, 0x00040017, 0x00000014,
    0x0000000B, 0x00000003, 0x0004002B, 0x0000000B, 0x00000A0D, 0x00000001,
    0x0004002B, 0x0000000B, 0x00000A10, 0x00000002, 0x0004002B, 0x0000000B,
    0x000008A6, 0x00FF00FF, 0x0004002B, 0x0000000B, 0x00000A22, 0x00000008,
    0x0004002B, 0x0000000B, 0x000005FD, 0xFF00FF00, 0x0004002B, 0x0000000B,
    0x00000A13, 0x00000003, 0x0004002B, 0x0000000B, 0x00000A3A, 0x00000010,
    0x0004002B, 0x0000000B, 0x00000A0A, 0x00000000, 0x0004002B, 0x0000000C,
    0x00000A1A, 0x00000005, 0x0004002B, 0x0000000B, 0x00000A19, 0x00000005,
    0x0004002B, 0x0000000C, 0x00000A20, 0x00000007, 0x0004002B, 0x0000000C,
    0x00000A35, 0x0000000E, 0x0004002B, 0x0000000C, 0x00000A11, 0x00000002,
    0x0004002B, 0x0000000C, 0x000009DB, 0xFFFFFFF0, 0x0004002B, 0x0000000C,
    0x00000A0E, 0x00000001, 0x0004002B, 0x0000000C, 0x00000A38, 0x0000000F,
    0x0004002B, 0x0000000C, 0x00000A17, 0x00000004, 0x0004002B, 0x0000000C,
    0x0000040B, 0xFFFFFE00, 0x0004002B, 0x0000000C, 0x00000A14, 0x00000003,
    0x0004002B, 0x0000000C, 0x00000A3B, 0x00000010, 0x0004002B, 0x0000000C,
    0x00000388, 0x000001C0, 0x0004002B, 0x0000000C, 0x00000A23, 0x00000008,
    0x0004002B, 0x0000000C, 0x00000A1D, 0x00000006, 0x0004002B, 0x0000000C,
    0x00000AC8, 0x0000003F, 0x0004002B, 0x0000000B, 0x00000A16, 0x00000004,
    0x0004002B, 0x0000000C, 0x0000078B, 0x0FFFFFFF, 0x0004002B, 0x0000000C,
    0x00000A05, 0xFFFFFFFE, 0x0004002B, 0x0000000B, 0x00000A6A, 0x00000020,
    0x000A001E, 0x00000489, 0x0000000B, 0x0000000B, 0x0000000B, 0x0000000B,
    0x00000014, 0x0000000B, 0x0000000B, 0x0000000B, 0x00040020, 0x00000706,
    0x00000002, 0x00000489, 0x0004003B, 0x00000706, 0x0000147D, 0x00000002,
    0x0004002B, 0x0000000C, 0x00000A0B, 0x00000000, 0x00040020, 0x00000288,
    0x00000002, 0x0000000B, 0x00040020, 0x00000291, 0x00000002, 0x00000014,
    0x00040020, 0x00000292, 0x00000001, 0x00000014, 0x0004003B, 0x00000292,
    0x00000F48, 0x00000001, 0x0006002C, 0x00000014, 0x00000A2B, 0x00000A13,
    0x00000A0A, 0x00000A0A, 0x00040017, 0x0000000F, 0x00000009, 0x00000002,
    0x0003001D, 0x000007DC, 0x00000017, 0x0003001E, 0x000007B4, 0x000007DC,
    0x00040020, 0x00000A31, 0x00000002, 0x000007B4, 0x0004003B, 0x00000A31,
    0x0000107A, 0x00000002, 0x00040020, 0x00000294, 0x00000002, 0x00000017,
    0x0003001D, 0x000007DD, 0x00000017, 0x0003001E, 0x000007B5, 0x000007DD,
    0x00040020, 0x00000A32, 0x00000002, 0x000007B5, 0x0004003B, 0x00000A32,
    0x0000140E, 0x00000002, 0x0006002C, 0x00000014, 0x00000BC3, 0x00000A16,
    0x00000A6A, 0x00000A0D, 0x0004002B, 0x0000000B, 0x00000A25, 0x00000009,
    0x0007002C, 0x00000017, 0x000009CE, 0x000008A6, 0x000008A6, 0x000008A6,
    0x000008A6, 0x0007002C, 0x00000017, 0x0000013D, 0x00000A22, 0x00000A22,
    0x00000A22, 0x00000A22, 0x0007002C, 0x00000017, 0x0000072E, 0x000005FD,
    0x000005FD, 0x000005FD, 0x000005FD, 0x0007002C, 0x00000017, 0x000002ED,
    0x00000A3A, 0x00000A3A, 0x00000A3A, 0x00000A3A, 0x00050036, 0x00000008,
    0x0000161F, 0x00000000, 0x00000502, 0x000200F8, 0x00003B06, 0x000300F7,
    0x00004C7A, 0x00000000, 0x000300FB, 0x00000A0A, 0x00002E68, 0x000200F8,
    0x00002E68, 0x00050041, 0x00000288, 0x000060D7, 0x0000147D, 0x00000A0B,
    0x0004003D, 0x0000000B, 0x00003526, 0x000060D7, 0x000500C7, 0x0000000B,
    0x00005FDC, 0x00003526, 0x00000A0D, 0x000500AB, 0x00000009, 0x00004376,
    0x00005FDC, 0x00000A0A, 0x000500C7, 0x0000000B, 0x00003028, 0x00003526,
    0x00000A10, 0x000500AB, 0x00000009, 0x00004384, 0x00003028, 0x00000A0A,
    0x000500C2, 0x0000000B, 0x00001EB0, 0x00003526, 0x00000A10, 0x000500C7,
    0x0000000B, 0x000061E2, 0x00001EB0, 0x00000A13, 0x00050041, 0x00000288,
    0x0000492C, 0x0000147D, 0x00000A0E, 0x0004003D, 0x0000000B, 0x00005EAC,
    0x0000492C, 0x00050041, 0x00000288, 0x00004EBA, 0x0000147D, 0x00000A11,
    0x0004003D, 0x0000000B, 0x00005788, 0x00004EBA, 0x00050041, 0x00000288,
    0x00004EBB, 0x0000147D, 0x00000A14, 0x0004003D, 0x0000000B, 0x00005789,
    0x00004EBB, 0x00050041, 0x00000291, 0x00004EBC, 0x0000147D, 0x00000A17,
    0x0004003D, 0x00000014, 0x0000578A, 0x00004EBC, 0x00050041, 0x00000288,
    0x00004EBD, 0x0000147D, 0x00000A1A, 0x0004003D, 0x0000000B, 0x0000578B,
    0x00004EBD, 0x00050041, 0x00000288, 0x00004E6E, 0x0000147D, 0x00000A1D,
    0x0004003D, 0x0000000B, 0x000019C2, 0x00004E6E, 0x0004003D, 0x00000014,
    0x00002A0E, 0x00000F48, 0x000500C4, 0x00000014, 0x0000538B, 0x00002A0E,
    0x00000A2B, 0x0007004F, 0x00000011, 0x000042F0, 0x0000538B, 0x0000538B,
    0x00000000, 0x00000001, 0x0007004F, 0x00000011, 0x0000242F, 0x0000578A,
    0x0000578A, 0x00000000, 0x00000001, 0x000500AE, 0x0000000F, 0x00004288,
    0x000042F0, 0x0000242F, 0x0004009A, 0x00000009, 0x00006067, 0x00004288,
    0x000300F7, 0x000019BA, 0x00000002, 0x000400FA, 0x00006067, 0x000055E8,
    0x000019BA, 0x000200F8, 0x000055E8, 0x000200F9, 0x00004C7A, 0x000200F8,
    0x000019BA, 0x0004007C, 0x00000016, 0x00005BB6, 0x0000538B, 0x00050051,
    0x0000000B, 0x00004916, 0x0000578A, 0x00000001, 0x00050051, 0x0000000C,
    0x00005BEB, 0x00005BB6, 0x00000000, 0x00050084, 0x0000000C, 0x0000591A,
    0x00005BEB, 0x00000A17, 0x00050051, 0x0000000C, 0x000018DA, 0x00005BB6,
    0x00000002, 0x0004007C, 0x0000000C, 0x000038A9, 0x00004916, 0x00050084,
    0x0000000C, 0x00002C0F, 0x000018DA, 0x000038A9, 0x00050051, 0x0000000C,
    0x000044BE, 0x00005BB6, 0x00000001, 0x00050080, 0x0000000C, 0x000056D4,
    0x00002C0F, 0x000044BE, 0x0004007C, 0x0000000C, 0x00005785, 0x000019C2,
    0x00050084, 0x0000000C, 0x00005FD7, 0x000056D4, 0x00005785, 0x00050080,
    0x0000000C, 0x00002042, 0x0000591A, 0x00005FD7, 0x0004007C, 0x0000000B,
    0x00002A92, 0x00002042, 0x00050080, 0x0000000B, 0x00002764, 0x00002A92,
    0x0000578B, 0x000500C2, 0x0000000B, 0x000054B5, 0x00002764, 0x00000A16,
    0x000300F7, 0x00005F43, 0x00000002, 0x000400FA, 0x00004376, 0x00005768,
    0x000051F2, 0x000200F8, 0x00005768, 0x000300F7, 0x00001E0B, 0x00000002,
    0x000400FA, 0x00004384, 0x00002BF8, 0x000018D9, 0x000200F8, 0x00002BF8,
    0x000500C3, 0x0000000C, 0x000032B3, 0x000044BE, 0x00000A17, 0x000500C3,
    0x0000000C, 0x0000601E, 0x000018DA, 0x00000A11, 0x000500C2, 0x0000000B,
    0x00004947, 0x00005789, 0x00000A16, 0x0004007C, 0x0000000C, 0x000018AA,
    0x00004947, 0x00050084, 0x0000000C, 0x00005321, 0x0000601E, 0x000018AA,
    0x00050080, 0x0000000C, 0x00003B27, 0x000032B3, 0x00005321, 0x000500C2,
    0x0000000B, 0x00002348, 0x00005788, 0x00000A19, 0x0004007C, 0x0000000C,
    0x00003901, 0x00002348, 0x00050084, 0x0000000C, 0x000020F4, 0x00003B27,
    0x00003901, 0x000500C3, 0x0000000C, 0x000032BA, 0x00005BEB, 0x00000A1A,
    0x00050080, 0x0000000C, 0x00005FEE, 0x000032BA, 0x000020F4, 0x000500C4,
    0x0000000C, 0x0000225D, 0x00005FEE, 0x00000A22, 0x000500C7, 0x0000000C,
    0x00002CF6, 0x0000225D, 0x0000078B, 0x000500C4, 0x0000000C, 0x000049FA,
    0x00002CF6, 0x00000A0E, 0x000500C7, 0x0000000C, 0x00004D38, 0x00005BEB,
    0x00000A20, 0x000500C7, 0x0000000C, 0x00003138, 0x000044BE, 0x00000A1D,
    0x000500C4, 0x0000000C, 0x0000454D, 0x00003138, 0x00000A11, 0x00050080,
    0x0000000C, 0x0000434B, 0x00004D38, 0x0000454D, 0x000500C4, 0x0000000C,
    0x00001B88, 0x0000434B, 0x00000A22, 0x000500C3, 0x0000000C, 0x00005DE3,
    0x00001B88, 0x00000A1D, 0x000500C3, 0x0000000C, 0x00002215, 0x000044BE,
    0x00000A14, 0x00050080, 0x0000000C, 0x000035A3, 0x00002215, 0x0000601E,
    0x000500C7, 0x0000000C, 0x00005A0C, 0x000035A3, 0x00000A0E, 0x000500C3,
    0x0000000C, 0x00004112, 0x00005BEB, 0x00000A14, 0x000500C4, 0x0000000C,
    0x0000496A, 0x00005A0C, 0x00000A0E, 0x00050080, 0x0000000C, 0x000034BD,
    0x00004112, 0x0000496A, 0x000500C7, 0x0000000C, 0x00004ADD, 0x000034BD,
    0x00000A14, 0x000500C4, 0x0000000C, 0x0000544A, 0x00004ADD, 0x00000A0E,
    0x00050080, 0x0000000C, 0x00003C4B, 0x00005A0C, 0x0000544A, 0x000500C7,
    0x0000000C, 0x0000335E, 0x00005DE3, 0x000009DB, 0x00050080, 0x0000000C,
    0x00004F70, 0x000049FA, 0x0000335E, 0x000500C4, 0x0000000C, 0x00005B31,
    0x00004F70, 0x00000A0E, 0x000500C7, 0x0000000C, 0x00005AEA, 0x00005DE3,
    0x00000A38, 0x00050080, 0x0000000C, 0x0000285C, 0x00005B31, 0x00005AEA,
    0x000500C7, 0x0000000C, 0x000047B4, 0x000018DA, 0x00000A14, 0x000500C4,
    0x0000000C, 0x0000544B, 0x000047B4, 0x00000A22, 0x00050080, 0x0000000C,
    0x00004157, 0x0000285C, 0x0000544B, 0x000500C7, 0x0000000C, 0x00004ADE,
    0x000044BE, 0x00000A0E, 0x000500C4, 0x0000000C, 0x0000544C, 0x00004ADE,
    0x00000A17, 0x00050080, 0x0000000C, 0x00004158, 0x00004157, 0x0000544C,
    0x000500C7, 0x0000000C, 0x00004FD6, 0x00003C4B, 0x00000A0E, 0x000500C4,
    0x0000000C, 0x00002703, 0x00004FD6, 0x00000A14, 0x000500C3, 0x0000000C,
    0x00003332, 0x00004158, 0x00000A1D, 0x000500C7, 0x0000000C, 0x000036D6,
    0x00003332, 0x00000A20, 0x00050080, 0x0000000C, 0x00003412, 0x00002703,
    0x000036D6, 0x000500C4, 0x0000000C, 0x00005B32, 0x00003412, 0x00000A14,
    0x000500C7, 0x0000000C, 0x00005AB1, 0x00003C4B, 0x00000A05, 0x00050080,
    0x0000000C, 0x00002A9C, 0x00005B32, 0x00005AB1, 0x000500C4, 0x0000000C,
    0x00005B33, 0x00002A9C, 0x00000A11, 0x000500C7, 0x0000000C, 0x00005AB2,
    0x00004158, 0x0000040B, 0x00050080, 0x0000000C, 0x00002A9D, 0x00005B33,
    0x00005AB2, 0x000500C4, 0x0000000C, 0x00005B34, 0x00002A9D, 0x00000A14,
    0x000500C7, 0x0000000C, 0x00005EA0, 0x00004158, 0x00000AC8, 0x00050080,
    0x0000000C, 0x000054ED, 0x00005B34, 0x00005EA0, 0x000200F9, 0x00001E0B,
    0x000200F8, 0x000018D9, 0x0004007C, 0x00000012, 0x000019AD, 0x000042F0,
    0x00050051, 0x0000000C, 0x000042C2, 0x000019AD, 0x00000000, 0x000500C3,
    0x0000000C, 0x000024FD, 0x000042C2, 0x00000A1A, 0x00050051, 0x0000000C,
    0x00002747, 0x000019AD, 0x00000001, 0x000500C3, 0x0000000C, 0x0000405C,
    0x00002747, 0x00000A1A, 0x000500C2, 0x0000000B, 0x00005B4D, 0x00005788,
    0x00000A19, 0x0004007C, 0x0000000C, 0x000018AB, 0x00005B4D, 0x00050084,
    0x0000000C, 0x00005347, 0x0000405C, 0x000018AB, 0x00050080, 0x0000000C,
    0x00003F5E, 0x000024FD, 0x00005347, 0x000500C4, 0x0000000C, 0x00004A8E,
    0x00003F5E, 0x00000A25, 0x000500C7, 0x0000000C, 0x00002AB6, 0x000042C2,
    0x00000A20, 0x000500C7, 0x0000000C, 0x00003139, 0x00002747, 0x00000A35,
    0x000500C4, 0x0000000C, 0x0000454E, 0x00003139, 0x00000A11, 0x00050080,
    0x0000000C, 0x00004397, 0x00002AB6, 0x0000454E, 0x000500C4, 0x0000000C,
    0x000018E7, 0x00004397, 0x00000A10, 0x000500C7, 0x0000000C, 0x000027B1,
    0x000018E7, 0x000009DB, 0x000500C4, 0x0000000C, 0x00002F76, 0x000027B1,
    0x00000A0E, 0x00050080, 0x0000000C, 0x00003C4C, 0x00004A8E, 0x00002F76,
    0x000500C7, 0x0000000C, 0x00003397, 0x000018E7, 0x00000A38, 0x00050080,
    0x0000000C, 0x00004D30, 0x00003C4C, 0x00003397, 0x000500C7, 0x0000000C,
    0x000047B5, 0x00002747, 0x00000A0E, 0x000500C4, 0x0000000C, 0x0000544D,
    0x000047B5, 0x00000A17, 0x00050080, 0x0000000C, 0x00004159, 0x00004D30,
    0x0000544D, 0x000500C7, 0x0000000C, 0x00005022, 0x00004159, 0x0000040B,
    0x000500C4, 0x0000000C, 0x00002416, 0x00005022, 0x00000A14, 0x000500C7,
    0x0000000C, 0x00004A33, 0x00002747, 0x00000A3B, 0x000500C4, 0x0000000C,
    0x00002F77, 0x00004A33, 0x00000A20, 0x00050080, 0x0000000C, 0x0000415A,
    0x00002416, 0x00002F77, 0x000500C7, 0x0000000C, 0x00004ADF, 0x00004159,
    0x00000388, 0x000500C4, 0x0000000C, 0x0000544E, 0x00004ADF, 0x00000A11,
    0x00050080, 0x0000000C, 0x00004144, 0x0000415A, 0x0000544E, 0x000500C7,
    0x0000000C, 0x00005083, 0x00002747, 0x00000A23, 0x000500C3, 0x0000000C,
    0x000041BF, 0x00005083, 0x00000A11, 0x000500C3, 0x0000000C, 0x00001EEC,
    0x000042C2, 0x00000A14, 0x00050080, 0x0000000C, 0x000035B6, 0x000041BF,
    0x00001EEC, 0x000500C7, 0x0000000C, 0x00005453, 0x000035B6, 0x00000A14,
    0x000500C4, 0x0000000C, 0x0000544F, 0x00005453, 0x00000A1D, 0x00050080,
    0x0000000C, 0x00003C4D, 0x00004144, 0x0000544F, 0x000500C7, 0x0000000C,
    0x0000374D, 0x00004159, 0x00000AC8, 0x00050080, 0x0000000C, 0x00002F42,
    0x00003C4D, 0x0000374D, 0x000200F9, 0x00001E0B, 0x000200F8, 0x00001E0B,
    0x000700F5, 0x0000000C, 0x0000292C, 0x000054ED, 0x00002BF8, 0x00002F42,
    0x000018D9, 0x000200F9, 0x00005F43, 0x000200F8, 0x000051F2, 0x0004007C,
    0x0000000C, 0x00003CBC, 0x00005789, 0x00050084, 0x0000000C, 0x000060B8,
    0x000018DA, 0x00003CBC, 0x00050080, 0x0000000C, 0x0000208E, 0x000060B8,
    0x000044BE, 0x0004007C, 0x0000000C, 0x000022F8, 0x00005788, 0x00050084,
    0x0000000C, 0x00001E9F, 0x0000208E, 0x000022F8, 0x00050080, 0x0000000C,
    0x00001F30, 0x0000591A, 0x00001E9F, 0x000200F9, 0x00005F43, 0x000200F8,
    0x00005F43, 0x000700F5, 0x0000000C, 0x00002A3E, 0x0000292C, 0x00001E0B,
    0x00001F30, 0x000051F2, 0x0004007C, 0x0000000C, 0x00001A3F, 0x00005EAC,
    0x00050080, 0x0000000C, 0x000056CD, 0x00001A3F, 0x00002A3E, 0x0004007C,
    0x0000000B, 0x00003EE9, 0x000056CD, 0x000500C2, 0x0000000B, 0x00005665,
    0x00003EE9, 0x00000A16, 0x00060041, 0x00000294, 0x00004315, 0x0000107A,
    0x00000A0B, 0x00005665, 0x0004003D, 0x00000017, 0x00001CAA, 0x00004315,
    0x000500AA, 0x00000009, 0x000035C0, 0x000061E2, 0x00000A0D, 0x000500AA,
    0x00000009, 0x00005376, 0x000061E2, 0x00000A10, 0x000500A6, 0x00000009,
    0x00005686, 0x000035C0, 0x00005376, 0x000300F7, 0x00003463, 0x00000000,
    0x000400FA, 0x00005686, 0x00002957, 0x00003463, 0x000200F8, 0x00002957,
    0x000500C7, 0x00000017, 0x0000475F, 0x00001CAA, 0x000009CE, 0x000500C4,
    0x00000017, 0x000024D1, 0x0000475F, 0x0000013D, 0x000500C7, 0x00000017,
    0x000050AC, 0x00001CAA, 0x0000072E, 0x000500C2, 0x00000017, 0x0000448D,
    0x000050AC, 0x0000013D, 0x000500C5, 0x00000017, 0x00003FF8, 0x000024D1,
    0x0000448D, 0x000200F9, 0x00003463, 0x000200F8, 0x00003463, 0x000700F5,
    0x00000017, 0x00005879, 0x00001CAA, 0x00005F43, 0x00003FF8, 0x00002957,
    0x000500AA, 0x00000009, 0x00004CB6, 0x000061E2, 0x00000A13, 0x000500A6,
    0x00000009, 0x00003B23, 0x00005376, 0x00004CB6, 0x000300F7, 0x00002C98,
    0x00000000, 0x000400FA, 0x00003B23, 0x00002B38, 0x00002C98, 0x000200F8,
    0x00002B38, 0x000500C4, 0x00000017, 0x00005E17, 0x00005879, 0x000002ED,
    0x000500C2, 0x00000017, 0x00003BE7, 0x00005879, 0x000002ED, 0x000500C5,
    0x00000017, 0x000029E8, 0x00005E17, 0x00003BE7, 0x000200F9, 0x00002C98,
    0x000200F8, 0x00002C98, 0x000700F5, 0x00000017, 0x00004D37, 0x00005879,
    0x00003463, 0x000029E8, 0x00002B38, 0x00060041, 0x00000294, 0x000060F9,
    0x0000140E, 0x00000A0B, 0x000054B5, 0x0003003E, 0x000060F9, 0x00004D37,
    0x00050080, 0x0000000B, 0x00003AC4, 0x000054B5, 0x00000A0E, 0x000600A9,
    0x0000000B, 0x00004958, 0x00004376, 0x00000A6A, 0x00000A3A, 0x000500C2,
    0x0000000B, 0x00002E1B, 0x00004958, 0x00000A16, 0x00050080, 0x0000000B,
    0x0000367B, 0x00005665, 0x00002E1B, 0x00060041, 0x00000294, 0x0000571A,
    0x0000107A, 0x00000A0B, 0x0000367B, 0x0004003D, 0x00000017, 0x000019B2,
    0x0000571A, 0x000300F7, 0x00003A1A, 0x00000000, 0x000400FA, 0x00005686,
    0x00002958, 0x00003A1A, 0x000200F8, 0x00002958, 0x000500C7, 0x00000017,
    0x00004760, 0x000019B2, 0x000009CE, 0x000500C4, 0x00000017, 0x000024D2,
    0x00004760, 0x0000013D, 0x000500C7, 0x00000017, 0x000050AD, 0x000019B2,
    0x0000072E, 0x000500C2, 0x00000017, 0x0000448E, 0x000050AD, 0x0000013D,
    0x000500C5, 0x00000017, 0x00003FF9, 0x000024D2, 0x0000448E, 0x000200F9,
    0x00003A1A, 0x000200F8, 0x00003A1A, 0x000700F5, 0x00000017, 0x00002AAC,
    0x000019B2, 0x00002C98, 0x00003FF9, 0x00002958, 0x000300F7, 0x00002C99,
    0x00000000, 0x000400FA, 0x00003B23, 0x00002B39, 0x00002C99, 0x000200F8,
    0x00002B39, 0x000500C4, 0x00000017, 0x00005E18, 0x00002AAC, 0x000002ED,
    0x000500C2, 0x00000017, 0x00003BE8, 0x00002AAC, 0x000002ED, 0x000500C5,
    0x00000017, 0x000029E9, 0x00005E18, 0x00003BE8, 0x000200F9, 0x00002C99,
    0x000200F8, 0x00002C99, 0x000700F5, 0x00000017, 0x00004D39, 0x00002AAC,
    0x00003A1A, 0x000029E9, 0x00002B39, 0x00060041, 0x00000294, 0x00001F75,
    0x0000140E, 0x00000A0B, 0x00003AC4, 0x0003003E, 0x00001F75, 0x00004D39,
    0x000200F9, 0x00004C7A, 0x000200F8, 0x00004C7A, 0x000100FD, 0x00010038,
};
