package unicorn
// For Unicorn Engine. AUTO-GENERATED FILE, DO NOT EDIT [arm_const.go]
const (

// ARM CPU

	CPU_ARM_926 = 0
	CPU_ARM_946 = 1
	CPU_ARM_1026 = 2
	CPU_ARM_1136_R2 = 3
	CPU_ARM_1136 = 4
	CPU_ARM_1176 = 5
	CPU_ARM_11MPCORE = 6
	CPU_ARM_CORTEX_M0 = 7
	CPU_ARM_CORTEX_M3 = 8
	CPU_ARM_CORTEX_M4 = 9
	CPU_ARM_CORTEX_M7 = 10
	CPU_ARM_CORTEX_M33 = 11
	CPU_ARM_CORTEX_R5 = 12
	CPU_ARM_CORTEX_R5F = 13
	CPU_ARM_CORTEX_A7 = 14
	CPU_ARM_CORTEX_A8 = 15
	CPU_ARM_CORTEX_A9 = 16
	CPU_ARM_CORTEX_A15 = 17
	CPU_ARM_TI925T = 18
	CPU_ARM_SA1100 = 19
	CPU_ARM_SA1110 = 20
	CPU_ARM_PXA250 = 21
	CPU_ARM_PXA255 = 22
	CPU_ARM_PXA260 = 23
	CPU_ARM_PXA261 = 24
	CPU_ARM_PXA262 = 25
	CPU_ARM_PXA270 = 26
	CPU_ARM_PXA270A0 = 27
	CPU_ARM_PXA270A1 = 28
	CPU_ARM_PXA270B0 = 29
	CPU_ARM_PXA270B1 = 30
	CPU_ARM_PXA270C0 = 31
	CPU_ARM_PXA270C5 = 32
	CPU_ARM_MAX = 33
	CPU_ARM_ENDING = 34

// ARM registers

	ARM_REG_INVALID = 0
	ARM_REG_APSR = 1
	ARM_REG_APSR_NZCV = 2
	ARM_REG_CPSR = 3
	ARM_REG_FPEXC = 4
	ARM_REG_FPINST = 5
	ARM_REG_FPSCR = 6
	ARM_REG_FPSCR_NZCV = 7
	ARM_REG_FPSID = 8
	ARM_REG_ITSTATE = 9
	ARM_REG_LR = 10
	ARM_REG_PC = 11
	ARM_REG_SP = 12
	ARM_REG_SPSR = 13
	ARM_REG_D0 = 14
	ARM_REG_D1 = 15
	ARM_REG_D2 = 16
	ARM_REG_D3 = 17
	ARM_REG_D4 = 18
	ARM_REG_D5 = 19
	ARM_REG_D6 = 20
	ARM_REG_D7 = 21
	ARM_REG_D8 = 22
	ARM_REG_D9 = 23
	ARM_REG_D10 = 24
	ARM_REG_D11 = 25
	ARM_REG_D12 = 26
	ARM_REG_D13 = 27
	ARM_REG_D14 = 28
	ARM_REG_D15 = 29
	ARM_REG_D16 = 30
	ARM_REG_D17 = 31
	ARM_REG_D18 = 32
	ARM_REG_D19 = 33
	ARM_REG_D20 = 34
	ARM_REG_D21 = 35
	ARM_REG_D22 = 36
	ARM_REG_D23 = 37
	ARM_REG_D24 = 38
	ARM_REG_D25 = 39
	ARM_REG_D26 = 40
	ARM_REG_D27 = 41
	ARM_REG_D28 = 42
	ARM_REG_D29 = 43
	ARM_REG_D30 = 44
	ARM_REG_D31 = 45
	ARM_REG_FPINST2 = 46
	ARM_REG_MVFR0 = 47
	ARM_REG_MVFR1 = 48
	ARM_REG_MVFR2 = 49
	ARM_REG_Q0 = 50
	ARM_REG_Q1 = 51
	ARM_REG_Q2 = 52
	ARM_REG_Q3 = 53
	ARM_REG_Q4 = 54
	ARM_REG_Q5 = 55
	ARM_REG_Q6 = 56
	ARM_REG_Q7 = 57
	ARM_REG_Q8 = 58
	ARM_REG_Q9 = 59
	ARM_REG_Q10 = 60
	ARM_REG_Q11 = 61
	ARM_REG_Q12 = 62
	ARM_REG_Q13 = 63
	ARM_REG_Q14 = 64
	ARM_REG_Q15 = 65
	ARM_REG_R0 = 66
	ARM_REG_R1 = 67
	ARM_REG_R2 = 68
	ARM_REG_R3 = 69
	ARM_REG_R4 = 70
	ARM_REG_R5 = 71
	ARM_REG_R6 = 72
	ARM_REG_R7 = 73
	ARM_REG_R8 = 74
	ARM_REG_R9 = 75
	ARM_REG_R10 = 76
	ARM_REG_R11 = 77
	ARM_REG_R12 = 78
	ARM_REG_S0 = 79
	ARM_REG_S1 = 80
	ARM_REG_S2 = 81
	ARM_REG_S3 = 82
	ARM_REG_S4 = 83
	ARM_REG_S5 = 84
	ARM_REG_S6 = 85
	ARM_REG_S7 = 86
	ARM_REG_S8 = 87
	ARM_REG_S9 = 88
	ARM_REG_S10 = 89
	ARM_REG_S11 = 90
	ARM_REG_S12 = 91
	ARM_REG_S13 = 92
	ARM_REG_S14 = 93
	ARM_REG_S15 = 94
	ARM_REG_S16 = 95
	ARM_REG_S17 = 96
	ARM_REG_S18 = 97
	ARM_REG_S19 = 98
	ARM_REG_S20 = 99
	ARM_REG_S21 = 100
	ARM_REG_S22 = 101
	ARM_REG_S23 = 102
	ARM_REG_S24 = 103
	ARM_REG_S25 = 104
	ARM_REG_S26 = 105
	ARM_REG_S27 = 106
	ARM_REG_S28 = 107
	ARM_REG_S29 = 108
	ARM_REG_S30 = 109
	ARM_REG_S31 = 110
	ARM_REG_C1_C0_2 = 111
	ARM_REG_C13_C0_2 = 112
	ARM_REG_C13_C0_3 = 113
	ARM_REG_IPSR = 114
	ARM_REG_MSP = 115
	ARM_REG_PSP = 116
	ARM_REG_CONTROL = 117
	ARM_REG_IAPSR = 118
	ARM_REG_EAPSR = 119
	ARM_REG_XPSR = 120
	ARM_REG_EPSR = 121
	ARM_REG_IEPSR = 122
	ARM_REG_PRIMASK = 123
	ARM_REG_BASEPRI = 124
	ARM_REG_BASEPRI_MAX = 125
	ARM_REG_FAULTMASK = 126
	ARM_REG_APSR_NZCVQ = 127
	ARM_REG_APSR_G = 128
	ARM_REG_APSR_NZCVQG = 129
	ARM_REG_IAPSR_NZCVQ = 130
	ARM_REG_IAPSR_G = 131
	ARM_REG_IAPSR_NZCVQG = 132
	ARM_REG_EAPSR_NZCVQ = 133
	ARM_REG_EAPSR_G = 134
	ARM_REG_EAPSR_NZCVQG = 135
	ARM_REG_XPSR_NZCVQ = 136
	ARM_REG_XPSR_G = 137
	ARM_REG_XPSR_NZCVQG = 138
	ARM_REG_CP_REG = 139
	ARM_REG_ENDING = 140

// alias registers
	ARM_REG_R13 = 12
	ARM_REG_R14 = 10
	ARM_REG_R15 = 11
	ARM_REG_SB = 75
	ARM_REG_SL = 76
	ARM_REG_FP = 77
	ARM_REG_IP = 78
)