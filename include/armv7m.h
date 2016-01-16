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

struct ASPR_t {
  uint32_t N : 1;  // 31
  uint32_t Z : 1;  // 30
  uint32_t C : 1;  // 29
  uint32_t V : 1;  // 28
  uint32_t Q : 1;  // 27
  uint32_t   : 7;  // 20 - 26
  uint32_t GE: 4;  // 16 - 19
  uint32_t   : 16; // 0 - 15
} __attribute__((packed));
typedef struct ASPR_t ASPR_t;

struct CONTROL_t {
  uint32_t       : 29 ;
  uint32_t FPCA  : 1;
  uint32_t SPSEL : 1;
  uint32_t nPRIV : 1;
} __attribute__((packed));
typedef struct CONTROL_t CONTROL_t;

struct FPSCR_t {
  uint32_t N     : 1;
  uint32_t Z     : 1;
  uint32_t C     : 1;
  uint32_t V     : 1;
  uint32_t       : 1;
  uint32_t AHP   : 1;
  uint32_t DN    : 1;
  uint32_t FZ    : 1;
  uint32_t RMode : 2;
  uint32_t       : 14;
  uint32_t IDC   : 1;
  uint32_t       : 2;
  uint32_t IXC   : 1;
  uint32_t UFC   : 1;
  uint32_t OFC   : 1;
  uint32_t DZC   : 1;
  uint32_t IOC   : 1;
} __attribute__((packed));
typedef struct FPSCR_t FPSCR_t;

// System Control Block type definitions

struct SCB_CPUID_t {
  uint32_t implementer : 8;
  uint32_t variant     : 4;
  uint32_t constant    : 4;
  uint32_t prartno     : 12;
  uint32_t revision    : 4;
} __attribute__((packed));
typedef struct SCB_CPUID_t SCB_CPUID_t;

struct SCB_ICSR_t {
  uint32_t NMIPENDSET : 1; // 31
  uint32_t            : 2; // 29-30
  uint32_t PENDSVSET  : 1; // 28
  uint32_t PENDSVCLR  : 1; // 27
  uint32_t PENDSTSET  : 1; // 26
  uint32_t PENDSTCLR  : 1; // 25
  uint32_t            : 1; // 24
  uint32_t ISRPREEMPT : 1; // 23
  uint32_t ISRPENDING : 1; // 22
  uint32_t            : 1; // 21
  uint32_t VECTPENDING: 9; // 12-20
  uint32_t RETTOBASE  : 1; // 11
  uint32_t            : 2; // 9-10
  uint32_t VECTACTIVE : 9; // 0-8
} __attribute__((packed));
typedef struct SCB_ICSR_t SCB_ICSR_t;

struct SCB_AIRCR_t {
  uint32_t VECTKEY      : 16;
  uint32_t ENDIANNESS   : 1;
  uint32_t              : 4;
  uint32_t PRIGROUP     : 3;
  uint32_t              : 5;
  uint32_t SYSRESETREQ  : 1;
  uint32_t VECTCLRACTIVE: 1;
  uint32_t VECTRESET    : 1;
} __attribute__((packed));
typedef struct SCB_AIRCR_t SCB_AIRCR_t;

struct SCB_SCR_t {
  uint32_t             : 27;
  uint32_t SEVONPEND   : 1;
  uint32_t             : 1;
  uint32_t SLEEPDEEP   : 1;
  uint32_t SLEEPONEXIT : 1;
  uint32_t             : 1;
} __attribute__((packed));
typedef struct SCB_SCR_t SCB_SCR_t;

struct SCB_CCR_t {
  uint32_t                : 22;
  uint32_t STKALIGN       : 1;
  uint32_t BFHFNMIGN      : 1;
  uint32_t                : 3;
  uint32_t DIV_0_TRP      : 1;
  uint32_t UNALIGN_TRP    : 1;
  uint32_t                : 1;
  uint32_t USERSETMPEND   : 1;
  uint32_t NONBASETHRDENA : 1;
} __attribute__((packed));
typedef struct SCB_CCR_t SCB_CCR_t;

struct SCB_SHPR1_t {
  uint32_t PRI_7 : 8;
  uint32_t PRI_6 : 8;
  uint32_t PRI_5 : 8;
  uint32_t PRI_4 : 8;
} __attribute__((packed));
typedef struct SCB_SHPR1_t SCB_SHPR1_t;

struct SCB_SHPR2_t {
  uint32_t PRI_11: 8;
  uint32_t PRI_10: 8;
  uint32_t PRI_9 : 8;
  uint32_t PRI_8 : 8;
} __attribute__((packed));
typedef struct SCB_SHPR2_t SCB_SHPR2_t;

struct SCB_SHPR3_t {
  uint32_t PRI_15 : 8;
  uint32_t PRI_14 : 8;
  uint32_t PRI_13 : 8;
  uint32_t PRI_12 : 8;
} __attribute__((packed));
typedef struct SCB_SHPR3_t SCB_SHPR3_t;

struct SCB_SHCSR_t {
  uint32_t               : 13;
  uint32_t USGFAULTENA   : 1;
  uint32_t BUSFAULTENA   : 1;
  uint32_t MEMFAULTENA   : 1;
  uint32_t SVCALLPENDED  : 1;
  uint32_t BUSFAULTPENDED: 1;
  uint32_t MEMFAULTPENDED: 1;
  uint32_t USGFAULTPENDED: 1;
  uint32_t SYSTICKACT    : 1;
  uint32_t PENDSVACT     : 1;
  uint32_t               : 1;
  uint32_t MONITORACT    : 1;
  uint32_t SVCALLACT     : 1;
  uint32_t               : 3;
  uint32_t USGFAULTACT   : 1;
  uint32_t               : 1;
  uint32_t BUSFAULTACT   : 1;
  uint32_t MEMFAULTACT   : 1;
} __attribute__((packed));
typedef struct SCB_SHCSR_t SCB_SHCSR_t;

struct SCB_CFSR_t {
  uint8_t MMARVALID  : 1;
  uint8_t            : 1;
  uint8_t MLSPERR    : 1;
  uint8_t MSTKERR    : 1;
  uint8_t MUNSTKER   : 1;
  uint8_t            : 1;
  uint8_t DACCVIOL   : 1;
  uint8_t IACCVIOL   : 1;

  uint8_t BFARVALID  : 1;
  uint8_t            : 1;
  uint8_t LSPERR     : 1;
  uint8_t STKERR     : 1;
  uint8_t UNSTKERR   : 1;
  uint8_t IMPRECISERR: 1;
  uint8_t PRECISERR  : 1;
  uint8_t IBUSERR    : 1;

  uint8_t            : 4;
  uint8_t NOCP       : 1;
  uint8_t INVPC      : 1;
  uint8_t INVSTATE   : 1;
  uint8_t UNDEFINSTR : 1;

  uint8_t            : 6;
  uint8_t DIVBYZERO  : 1;
  uint8_t UNALIGNED  : 1;
} __attribute__((packed));
typedef struct SCB_CFSR_t SCB_CFSR_t;

struct SCB_HFSR_t {
  uint32_t DEBUGEVT: 1;
  uint32_t FORCED  : 1;
  uint32_t         : 28;
  uint32_t VECTTBL : 1;
  uint32_t         : 1;
} __attribute__((packed));
typedef struct SCB_HFSR_t SCB_HFSR_t;

enum {
  coprocessor_access_denied     = 0,
  coprocessor_access_privileged = 1,
  coprocessor_access_full       = 3
};

struct SCB_CPACR_t {
  uint32_t      : 8;
  uint32_t CP11 : 2;
  uint32_t CP10 : 2;
  uint32_t      : 4;
  uint32_t CP7  : 2;
  uint32_t CP6  : 2;
  uint32_t CP5  : 2;
  uint32_t CP4  : 2;
  uint32_t CP3  : 2;
  uint32_t CP2  : 2;
  uint32_t CP1  : 2;
  uint32_t CP0  : 2;
} __attribute__((packed));
typedef struct SCB_CPACR_t SCB_CPACR_t;

struct SCB_FPCCR_t {
  uint32_t ASPEN : 1;
  uint32_t LSPEN : 1;
  uint32_t       : 21;
  uint32_t MONRDY: 1;
  uint32_t       : 1;
  uint32_t BFRDY : 1;
  uint32_t MMRDY : 1;
  uint32_t HFRDY : 1;
  uint32_t THREAD: 1;
  uint32_t       : 1;
  uint32_t USER  : 1;
  uint32_t LSPACT: 1;
} __attribute__((packed));
typedef struct SCB_FPCCR_t SCB_FPCCR_t;

enum {
  fp_rounding_nearest        = 0,
  fp_rounding_plus_infinity  = 1,
  fp_rounding_minus_infinity = 2,
  fp_rounding_to_zero        = 3
};

struct SCB_FPDSCR_t {
  uint32_t      : 5;
  uint32_t AHP  : 1;
  uint32_t DN   : 1;
  uint32_t FZ   : 1;
  uint32_t RMode: 2;
  uint32_t      : 22;
} __attribute__((packed));
typedef struct SCB_FPDSCR_t SCB_FPDSCR_t;

struct SCB_MVFR0_t {
  uint32_t FP_rouning_mode       : 4;
  uint32_t Short_vectors         : 4;
  uint32_t Square_root           : 4;
  uint32_t Divide                : 4;
  uint32_t FP_exception_trapping : 4;
  uint32_t Double_precision      : 4;
  uint32_t Single_precision      : 4;
  uint32_t A_SIMD_registers      : 4;
} __attribute__((packed));
typedef struct SCB_MVFR0_t SCB_MVFR0_t;

struct SCB_MVFR1_t {
  uint32_t FP_fused_MAC : 4;
  uint32_t FP_HPFP      : 4;
  uint32_t              : 16;
  uint32_t D_NaN_mode   : 4;
  uint32_t FtZ_mode     : 4;
} __attribute__((packed));
typedef struct SCB_MVFR1_t SCB_MVFR1_t;

// SysTick Register types
struct SYSST_SCR_t {
  uint32_t           : 15;
  uint32_t COUNTFLAG : 1;
  uint32_t           : 13;
  uint32_t CLKSOURCE : 1;
  uint32_t TICKINT   : 1;
  uint32_t ENABLE    : 1;
} __attribute__((packed));
typedef struct SYSST_SCR_t SYSST_SCR_t;

struct SYST_CALIB_t {
  uint32_t NOREF : 1;
  uint32_t SKEW  : 1;
  uint32_t       : 6;
  uint32_t TENMS : 24;
} __attribute__((packed));
typedef struct SYST_CALIB_t SYST_CALIB_t;

// MPU Registers types
struct MPU_TYPE_t {
  uint32_t         : 8;
  uint32_t IREGION : 8;
  uint32_t DREGION : 8;
  uint32_t         : 7;
  uint32_t SEPARATE: 1;
} __attribute__((packed));
typedef struct MPU_TYPE_t MPU_TYPE_t;

struct MPU_CTRL_t {
  uint32_t            : 29;
  uint32_t PRIVDEFENA : 1;
  uint32_t HFNMIENA   : 1;
  uint32_t ENABLE     : 1;
} __attribute__((packed));
typedef struct MPU_CTRL_t MPU_CTRL_t;

struct MPU_RBAR_t {
  uint32_t ADDR  : 27;
  uint32_t VALID : 1;
  uint32_t REGION: 4;
} __attribute__((packed));
typedef struct MPU_RBAR_t MPU_RBAR_t;

struct MPU_RASR_t {
  uint32_t       : 3;
  uint32_t XN    : 1;
  uint32_t       : 1;
  uint32_t AP    : 3;
  uint32_t       : 2;
  uint32_t TEX   : 3;
  uint32_t S     : 1;
  uint32_t C     : 1;
  uint32_t B     : 1;
  uint32_t SRD   : 8;
  uint32_t       : 2;
  uint32_t SIZE  : 5;
  uint32_t ENABLE: 1;
} __attribute__((packed));
typedef struct MPU_RASR_t MPU_RASR_t;

// System Control Block registers declarations

extern volatile const SCB_CPUID_t
SCB_CPUID;

extern volatile SCB_ICSR_t
SCB_ICSR;

extern volatile SCB_AIRCR_t
SCB_AIRCR;

extern volatile SCB_SCR_t
SCB_SCR;

extern volatile SCB_CCR_t
SCB_CCR;

extern volatile SCB_SHPR1_t
SCB_SHPR1;

extern volatile SCB_SHPR2_t
SCB_SHPR2;

extern volatile SCB_SHPR3_t
SCB_SHPR3;

extern volatile SCB_SHCSR_t
SCB_SHCSR;

extern volatile SCB_CFSR_t
SCB_CFSR;

extern volatile SCB_HFSR_t
SCB_HFSR;

extern volatile void *
SCB_MMFAR;

extern volatile void *
SCB_BFAR;

extern volatile SCB_CPACR_t
SCB_CPACR;

extern volatile SCB_FPCCR_t
SCB_FPCCR;

extern volatile void *
SCB_FPCAR;

extern volatile SCB_FPDSCR_t
SCB_FPDSCR;

extern volatile uint32_t
SCB_ICTR;

extern volatile uint32_t
SCB_STIR;

extern volatile const SCB_MVFR0_t
SCB_MVFR0;

extern volatile const SCB_MVFR1_t
SCB_MVFR1;

extern volatile 
#ifndef CUSTOM_SCB_VTOR_T
void *
#else
SCB_VTOR_t
#endif
SCB_VTOR;

// SysTick Register declaration
extern volatile SYSST_SCR_t
SYSST_SCR;

extern volatile uint32_t
SYST_CVR;

extern volatile uint32_t
SYST_CVR;

extern volatile const SYST_CALIB_t
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
extern volatile const MPU_TYPE_t
MPU_TYPE;

extern volatile MPU_CTRL_t
MPU_CTRL;

extern volatile uint32_t
MPU_RNR;

extern volatile MPU_RBAR_t
MPU_RBAR;

extern volatile MPU_RASR_t
MPU_RASR;

#endif // _ARMV7M_H
