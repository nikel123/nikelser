/**
 * Copyright (c) 2013-2015 Andrej Gelenberg <andrej.gelenberg@udo.edu>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _ARMV7M_H
#define _ARMV7M_H

#include <bitfield.h>

// CPU Registers types


// Application Program Status Registe
bf_reg_funcs(32, APSR_N,  31, 1)
bf_reg_funcs(32, APSR_Z,  30, 1)
bf_reg_funcs(32, APSR_C,  29, 1)
bf_reg_funcs(32, APSR_V,  28, 1)
bf_reg_funcs(32, APSR_Q,  27, 1)
bf_reg_funcs(32, APSR_GE, 16, 4)

bf_reg_funcs(32, CONTROL_nPRIV, 0, 1)
bf_reg_funcs(32, CONTROL_SPSEL, 1, 1)
bf_reg_funcs(32, CONTROL_FPCS,  2, 1)

// Floating-point Status and Control Register

bf_reg_funcs(32, FPSCR_N,     31, 1)
bf_reg_funcs(32, FPSCR_Z,     30, 1)
bf_reg_funcs(32, FPSCR_C,     29, 1)
bf_reg_funcs(32, FPSCR_V,     28, 1)
bf_reg_funcs(32, FPSCR_AHP,   26, 1)
bf_reg_funcs(32, FPSCR_DN,    25, 1)
bf_reg_funcs(32, FPSCR_FZ,    24, 1)
bf_reg_funcs(32, FPSCR_RMode, 22, 2)
bf_reg_funcs(32, FPSCR_IDC,    7, 1)
bf_reg_funcs(32, FPSCR_IXC,    4, 1)
bf_reg_funcs(32, FPSCR_UFC,    3, 1)
bf_reg_funcs(32, FPSCR_OFC,    2, 1)
bf_reg_funcs(32, FPSCR_DZC,    1, 1)
bf_reg_funcs(32, FPSCR_IOC,    0, 1)

// System Control Block type definitions

bf_reg_funcs(32, SCB_CPUID_IMPLEMENTER, 24,  8)
bf_reg_funcs(32, SCB_CPUID_VARIANT,     20,  4)
bf_reg_funcs(32, SCB_CPUID_PARTNO,       4, 12)
bf_reg_funcs(32, SCB_CPUID_REVISION,     0,  4)

extern const uint32_t
SCB_CPUID;

bf_reg_funcs(32, SCB_ICSR_NMIPENDSET, 31, 1)
bf_reg_funcs(32, SCB_ICSR_PENDSVSET,  28, 1)
bf_reg_funcs(32, SCB_ICSR_PENDSVCLR,  27, 1)
bf_reg_funcs(32, SCB_ICSR_PENDSTSET,  26, 1)
bf_reg_funcs(32, SCB_ICSR_PENDSTCLR,  25, 1)
bf_reg_funcs(32, SCB_ICSR_ISRPREEMPT, 23, 1)
bf_reg_funcs(32, SCB_ICSR_ISRPENDING, 22, 1)
bf_reg_funcs(32, SCB_ICSR_VECTPENDING,12, 9)
bf_reg_funcs(32, SCB_ICSR_RETTOBASE,  11, 1)
bf_reg_funcs(32, SCB_ICSR_VECTACTIVE,  0, 9)

extern volatile uint32_t
SCB_ICSR;

extern volatile void *
SCB_VTOR;

extern volatile uint32_t
SCB_ACTLR;

bf_reg_funcs(32, SCB_AIRCR_VECTKEY,     16, 16)
bf_reg_funcs(32, SCB_AIRCR_VECTKEYSTAT, 16, 16)
bf_reg_funcs(32, SCB_AIRCR_ENDIANNESS,  15,  1)
bf_reg_funcs(32, SCB_AIRCR_PRIGROUP,     8,  3)
bf_reg_funcs(32, SCB_AIRCR_SYSRESETREQ,  2,  1)
bf_reg_funcs(32, SCB_AIRCR_VECTCLRACTIVE,1,  1)
bf_reg_funcs(32, SCB_AIRCR_VECTRESET,    0,  1)

extern volatile uint32_t
SCB_AIRCR;

bf_reg_funcs(32, SCB_SCR_SEVONPEND,   4, 1)
bf_reg_funcs(32, SCB_SCR_SLEEPDEEP,   2, 1)
bf_reg_funcs(32, SCB_SCR_SLEEPONEXIT, 1, 1)

extern volatile uint32_t
SCB_SCR;

bf_reg_funcs(32, SCB_CCR_STKALIGN,       9, 1)
bf_reg_funcs(32, SCB_CCR_BFHFNMIGN,      8, 1)
bf_reg_funcs(32, SCB_CCR_DIV_0_TRP,      4, 1)
bf_reg_funcs(32, SCB_CCR_UNALIGN_TRP,    3, 1)
bf_reg_funcs(32, SCB_CCR_USERSETMPEND,   1, 1)
bf_reg_funcs(32, SCB_CCR_NONBASETHRDENA, 0, 1)

extern volatile uint32_t
SCB_CCR;

extern volatile uint8_t
SCB_SHPR1_PRI_7;

extern volatile uint8_t
SCB_SHPR1_PRI_6;

extern volatile uint8_t
SCB_SHPR1_PRI_5;

extern volatile uint8_t
SCB_SHPR1_PRI_4;

extern volatile uint8_t
SCB_SHPR2_PRI_11;

extern volatile uint8_t
SCB_SHPR2_PRI_10;

extern volatile uint8_t
SCB_SHPR2_PRI_9;

extern volatile uint8_t
SCB_SHPR2_PRI_8;

extern volatile uint8_t
SCB_SHPR3_PRI_15;

extern volatile uint8_t
SCB_SHPR3_PRI_14;

extern volatile uint8_t
SCB_SHPR3_PRI_13;

extern volatile uint8_t
SCB_SHPR3_PRI_12;

bf_reg_funcs(32, SCB_SHCSR_USGFAULTENA,    18, 1)
bf_reg_funcs(32, SCB_SHCSR_BUSFAULTENA,    17, 1)
bf_reg_funcs(32, SCB_SHCSR_MEMFAULTENA,    16, 1)
bf_reg_funcs(32, SCB_SHCSR_SVCALLPENDED,   15, 1)
bf_reg_funcs(32, SCB_SHCSR_BUSFAULTPENDED, 14, 1)
bf_reg_funcs(32, SCB_SHCSR_MEMFAULTPENDED, 13, 1)
bf_reg_funcs(32, SCB_SHCSR_USGFAULTPENDED, 12, 1)
bf_reg_funcs(32, SCB_SHCSR_SYSTICKACT,     11, 1)
bf_reg_funcs(32, SCB_SHCSR_PENDSVACT,      10, 1)
bf_reg_funcs(32, SCB_SHCSR_MONITORACT,      8, 1)
bf_reg_funcs(32, SCB_SHCSR_SVCALLACT,       7, 1)
bf_reg_funcs(32, SCB_SHCSR_USGFAULTACT,     3, 1)
bf_reg_funcs(32, SCB_SHCSR_BUSFAULTACT,     1, 1)
bf_reg_funcs(32, SCB_SHCSR_MEMFAULTACT,     0, 1)

extern volatile uint32_t
SCB_SHCSR;

bf_reg_funcs(8, SCB_CFSR_MMFSR_MMARVALID, 7, 1)
bf_reg_funcs(8, SCB_CFSR_MMFSR_MLSPERR,   5, 1)
bf_reg_funcs(8, SCB_CFSR_MMFSR_MSTKERR,   4, 1)
bf_reg_funcs(8, SCB_CFSR_MMFSR_MUNSTKER,  3, 1)
bf_reg_funcs(8, SCB_CFSR_MMFSR_DACCVIOL,  1, 1)
bf_reg_funcs(8, SCB_CFSR_MMFSR_IACCVIOL,  0, 1)

extern volatile uint16_t
SCB_CFSR_MMFSR;

bf_reg_funcs(8, SCB_CFSR_BFSR_BFARVALID,   7, 1)
bf_reg_funcs(8, SCB_CFSR_BFSR_LSPERR,      5, 1)
bf_reg_funcs(8, SCB_CFSR_BFSR_STKERR,      4, 1)
bf_reg_funcs(8, SCB_CFSR_BFSR_UNSTKERR,    3, 1)
bf_reg_funcs(8, SCB_CFSR_BFSR_IMPRECISERR, 2, 1)
bf_reg_funcs(8, SCB_CFSR_BFSR_PRECISERR,   1, 1)
bf_reg_funcs(8, SCB_CFSR_BFSR_IBUSERR,     0, 1)

extern volatile uint16_t
SCB_CFSR_BFSR;

bf_reg_funcs(16, SCB_CFSR_UFSR_DIVBYZERO, 9, 1)
bf_reg_funcs(16, SCB_CFSR_UFSR_UNALIGNED, 8, 1)
bf_reg_funcs(16, SCB_CFSR_UFSR_NOCP,      3, 1)
bf_reg_funcs(16, SCB_CFSR_UFSR_INVPC,     2, 1)
bf_reg_funcs(16, SCB_CFSR_UFSR_INVSTATE,  1, 1)
bf_reg_funcs(16, SCB_CFSR_UFSR_UNDEFINSTR,0, 1)

extern volatile uint16_t
SCB_CFSR_UFSR;

bf_reg_funcs(32, SCB_HFSR_DEBUGEVT, 31, 1)
bf_reg_funcs(32, SCB_HFSR_FORCED,   30, 1)
bf_reg_funcs(32, SCB_HFSR_VECTTBL,   1, 1)

extern volatile uint32_t
SCB_HFSR;

enum {
  coprocessor_access_denied     = 0,
  coprocessor_access_privileged = 1,
  coprocessor_access_full       = 3
};

extern volatile void *
SCB_MMFAR;

extern volatile void *
SCB_BFAR;

bf_reg_funcs(32, SCB_CPACR_CP11, 22, 2)
bf_reg_funcs(32, SCB_CPACR_CP10, 20, 2)
bf_reg_funcs(32, SCB_CPACR_CP7,  14, 2)
bf_reg_funcs(32, SCB_CPACR_CP6,  12, 2)
bf_reg_funcs(32, SCB_CPACR_CP5,  10, 2)
bf_reg_funcs(32, SCB_CPACR_CP4,   8, 2)
bf_reg_funcs(32, SCB_CPACR_CP3,   6, 2)
bf_reg_funcs(32, SCB_CPACR_CP2,   4, 2)
bf_reg_funcs(32, SCB_CPACR_CP1,   2, 2)
bf_reg_funcs(32, SCB_CPACR_CP0,   0, 2)

extern volatile uint32_t
SCB_CPACR;

bf_reg_funcs(32, SCB_FPCCR_ASPEN, 31, 1)
bf_reg_funcs(32, SCB_FPCCR_LSPEN, 30, 1)
bf_reg_funcs(32, SCB_FPCCR_MONRDY, 8, 1)
bf_reg_funcs(32, SCB_FPCCR_BFRDY,  6, 1)
bf_reg_funcs(32, SCB_FPCCR_MMRDY,  5, 1)
bf_reg_funcs(32, SCB_FPCCR_HFRDY,  4, 1)
bf_reg_funcs(32, SCB_FPCCR_THREAD, 3, 1)
bf_reg_funcs(32, SCB_FPCCR_USER,   1, 1)
bf_reg_funcs(32, SCB_FPCCR_LSPACT, 0, 1)

extern volatile uint32_t
SCB_FPCCR;


extern volatile void *
SCB_FPCAR;

enum {
  fp_rounding_nearest        = 0,
  fp_rounding_plus_infinity  = 1,
  fp_rounding_minus_infinity = 2,
  fp_rounding_to_zero        = 3
};

bf_reg_funcs(32, SCB_FPDSCR_AHP,   26, 1)
bf_reg_funcs(32, SCB_FPDSCR_DN,    25, 1)
bf_reg_funcs(32, SCB_FPDSCR_FZ,    24, 1)
bf_reg_funcs(32, SCB_FPDSCR_RMode, 22, 2)

extern volatile uint32_t
SCB_FPDSCR;

extern volatile uint32_t
SCB_ICTR;

extern volatile uint32_t
SCB_STIR;

bf_reg_funcs(32, SCB_MVFR0_FP_rouning_mode,       28, 4)
bf_reg_funcs(32, SCB_MVFR0_Short_vectors,         24, 4)
bf_reg_funcs(32, SCB_MVFR0_Square_root,           20, 4)
bf_reg_funcs(32, SCB_MVFR0_Divide,                16, 4)
bf_reg_funcs(32, SCB_MVFR0_FP_exception_trapping, 12, 4)
bf_reg_funcs(32, SCB_MVFR0_Double_precision,       8, 4)
bf_reg_funcs(32, SCB_MVFR0_Single_precision,       4, 4)
bf_reg_funcs(32, SCB_MVFR0_A_SIMD_registers,       0, 4)

extern volatile uint32_t
SCB_MVFR0;

bf_reg_funcs(32, SCB_MVFR1_FP_fused_MAC, 28, 4)
bf_reg_funcs(32, SCB_MVFR1_FP_HPFP,      24, 4)
bf_reg_funcs(32, SCB_MVFR1_D_NaN_mode,    4, 4)
bf_reg_funcs(32, SCB_MVFR1_FtZ_mode,      0, 4)

extern volatile uint32_t
SCB_MVFR1;

// SysTick Register types

bf_reg_funcs(32, SYSST_SCR_COUNTFLAG, 16, 1)
bf_reg_funcs(32, SYSST_SCR_CLKSOURCE,  2, 1)
bf_reg_funcs(32, SYSST_SCR_TICKINT,    1, 1)
bf_reg_funcs(32, SYSST_SCR_ENABLE,     0, 1)

extern volatile uint32_t
SYSST_SCR;

extern volatile uint32_t
SYST_CVR;

extern volatile uint32_t
SYST_CVR;

bf_reg_funcs(32, SYST_CALIB_NOREF, 31,  1)
bf_reg_funcs(32, SYST_CALIB_SKEW,  30,  1)
bf_reg_funcs(32, SYST_CALIB_TENMS,  0, 24)

extern volatile uint32_t
SYST_CALIB;

// NVIC Registers declaration

extern volatile uint32_t
NVIC_ISER[16];

extern volatile uint32_t
NVIC_ICER[16];

extern volatile uint32_t
NVIC_ISPR[16];

extern volatile uint32_t
NVIC_ICPR[16];

extern volatile const uint32_t
NVIC_IABR[16];

extern volatile uint8_t
NVIC_IPR[496];

// MPU Registers declaration

bf_reg_funcs(32, MPU_TYPE_IREGION, 16, 8)
bf_reg_funcs(32, MPU_TYPE_DREGION,  8, 8)
bf_reg_funcs(32, MPU_TYPE_SEPARATE, 0, 1)

extern const uint32_t
MPU_TYPE;

bf_reg_funcs(32, MPU_CTRL_PRIVDEFENA, 2, 1)
bf_reg_funcs(32, MPU_CTRL_HFNMIENA,   1, 1)
bf_reg_funcs(32, MPU_CTRL_ENABLE,     0, 1)

extern volatile uint32_t
MPU_CTRL;

extern volatile uint32_t
MPU_RNR;

bf_reg_funcs(32, MPU_RBAR_ADDR,   5, 27)
bf_reg_funcs(32, MPU_RBAR_VALID,  4,  1)
bf_reg_funcs(32, MPU_RBAR_REGION, 0,  4)

extern volatile uint32_t
MPU_RBAR;

bf_reg_funcs(32, MPU_RASR_XN,    28, 1)
bf_reg_funcs(32, MPU_RASR_AP,    24, 3)
bf_reg_funcs(32, MPU_RASR_TEX,   19, 3)
bf_reg_funcs(32, MPU_RASR_S,     18, 1)
bf_reg_funcs(32, MPU_RASR_C,     17, 1)
bf_reg_funcs(32, MPU_RASR_B,     16, 1)
bf_reg_funcs(32, MPU_RASR_SRD,    8, 8)
bf_reg_funcs(32, MPU_RASR_SIZE,   1, 5)
bf_reg_funcs(32, MPU_RASR_ENABLE, 0, 1)

extern volatile uint32_t
MPU_RASR;

#endif // _ARMV7M_H
