#ifndef _STM32F3_RCC_H
#define _STM32F3_RCC_H

#include <stdint.h>
#include <bitfield.h>
#include <stddef.h>

inline void *
RCC_BASE() {
  return (void *)0x40021000;
}

inline volatile uint32_t *
RCC_REG(size_t offset) {
  return (volatile uint32_t *)(RCC_BASE() + offset);
}

inline volatile uint8_t *
RCC_REG8(size_t offset) {
  return (volatile uint8_t *)(RCC_BASE() + offset);
}

inline volatile uint16_t *
RCC_REG16(size_t offset) {
  return (volatile uint16_t *)(RCC_BASE() + offset);
}

bf_reg_funcs(32, RCC_CR_PLLRDY, 25, 1)
bf_reg_funcs(32, RCC_CR_PLLON,  24, 1)
bf_reg_funcs(32, RCC_CR_CSSON,  19, 1)
bf_reg_funcs(32, RCC_CR_HSEBYP, 18, 1)
bf_reg_funcs(32, RCC_CR_HSERDY, 17, 1)
bf_reg_funcs(32, RCC_CR_HSEON,  16, 1)
bf_reg_funcs(32, RCC_CR_HSICAL,  8, 8)
bf_reg_funcs(32, RCC_CR_HSITRIM, 3, 5)
bf_reg_funcs(32, RCC_CR_HSIRDY,  1, 1)
bf_reg_funcs(32, RCC_CR_HSION,   0, 1)

inline volatile uint32_t *
RCC_CR() {
  return RCC_REG(0x0);
}

bf_reg_funcs(8, RCC_HSI_TRIM, 3, 5)
bf_reg_funcs(8, RCC_HSI_RDY,  1, 1)
bf_reg_funcs(8, RCC_HSI_ON,   0, 1)

inline volatile uint8_t *
RCC_HSI() {
  return RCC_REG8(0x0);
}

inline const uint8_t *
RCC_HSICAL() {
  return (const uint8_t *)RCC_REG8(0x1);
}

bf_reg_funcs(8, RCC_HSE_CSSON, 3, 1)
bf_reg_funcs(8, RCC_HSE_BYP,   2, 1)
bf_reg_funcs(8, RCC_HSE_RDY,   1, 1)
bf_reg_funcs(8, RCC_HSE_ON,    0, 1)

inline volatile uint8_t *
RCC_HSE() {
  return RCC_REG8(0x2);
}

bf_reg_funcs(8, RCC_PLL_RDY, 1, 1)
bf_reg_funcs(8, RCC_PLL_ON,  0, 1)

inline volatile uint8_t *
RCC_PLL() {
  return RCC_REG8(0x3);
}

enum {
  RCC_CFGR_PLLDIV_2 = 0,
  RCC_CFGR_PLLDIV_1 = 1,

  RCC_CFGR_MCOPRE_DIV1   = 0,
  RCC_CFGR_MCOPRE_DIV2   = 1,
  RCC_CFGR_MCOPRE_DIV4   = 2,
  RCC_CFGR_MCOPRE_DIV8   = 3,
  RCC_CFGR_MCOPRE_DIV16  = 4,
  RCC_CFGR_MCOPRE_DIV32  = 5,
  RCC_CFGR_MCOPRE_DIV64  = 6,
  RCC_CFGR_MCOPRE_DIV128 = 7,

  RCC_CFGR_MCO_DISABLED = 0,
  RCC_CFGR_MCO_LSI      = 2,
  RCC_CFGR_MCO_LSE      = 3,
  RCC_CFGR_MCO_SYSCLK   = 4,
  RCC_CFGR_MCO_HSI      = 5,
  RCC_CFGR_MCO_HSE      = 6,
  RCC_CFGR_MCO_PLL      = 7,

  RCC_CFGR_I2SSRC_SYSCLK = 0,
  RCC_CFGR_I2SSRC_EXTERN = 1,

  RCC_CFGR_PLLMUL_x2  = 0,
  RCC_CFGR_PLLMUL_x3  = 1,
  RCC_CFGR_PLLMUL_x4  = 2,
  RCC_CFGR_PLLMUL_x5  = 3,
  RCC_CFGR_PLLMUL_x6  = 4,
  RCC_CFGR_PLLMUL_x7  = 5,
  RCC_CFGR_PLLMUL_x8  = 6,
  RCC_CFGR_PLLMUL_x9  = 7,
  RCC_CFGR_PLLMUL_x10 = 8,
  RCC_CFGR_PLLMUL_x11 = 9,
  RCC_CFGR_PLLMUL_x12 = 10,
  RCC_CFGR_PLLMUL_x13 = 11,
  RCC_CFGR_PLLMUL_x14 = 12,
  RCC_CFGR_PLLMUL_x15 = 13,
  RCC_CFGR_PLLMUL_x16 = 14,

  RCC_CFGR_PLLXTPRE_DIV1 = 0,
  RCC_CFGR_PLLXTPRE_DIV2 = 1,

  RCC_CFGR_PLLSRC_HSI_DIV2 = 0,
  RCC_CFGR_PLLSRC_HSI      = 1,
  RCC_CFGR_PLLSRC_HSE      = 2,

  RCC_CFGR_PPRE_DIV1  = 0,
  RCC_CFGR_PPRE_DIV2  = 1,
  RCC_CFGR_PPRE_DIV4  = 2,
  RCC_CFGR_PPRE_DIV8  = 3,
  RCC_CFGR_PPRE_DIV16 = 4,

  RCC_CFGR_HPRE_DIV1   =  0,
  RCC_CFGR_HPRE_DIV2   =  8,
  RCC_CFGR_HPRE_DIV4   =  9,
  RCC_CFGR_HPRE_DIV8   = 10,
  RCC_CFGR_HPRE_DIV16  = 11,
  RCC_CFGR_HPRE_DIV64  = 12,
  RCC_CFGR_HPRE_DIV128 = 13,
  RCC_CFGR_HPRE_DIV256 = 14,
  RCC_CFGR_HPRE_DIV512 = 15,

  RCC_CFGR_SW_HSI = 0,
  RCC_CFGR_SW_HSE = 1,
  RCC_CFGR_SW_PLL = 2,
};

bf_reg_funcs(32, RCC_CFGR_PLLNODIV, 31, 1)
bf_reg_funcs(32, RCC_CFGR_MCOPRE,   28, 3)
bf_reg_funcs(32, RCC_CFGR_MCOF,     28, 1)
bf_reg_funcs(32, RCC_CFGR_MCO,      24, 3)
bf_reg_funcs(32, RCC_CFGR_I2SSRC,   23, 1)
bf_reg_funcs(32, RCC_CFGR_USBPRES,  22, 1)
bf_reg_funcs(32, RCC_CFGR_PLLMUL,   18, 4)
bf_reg_funcs(32, RCC_CFGR_PLLXTPRE, 17, 1)
bf_reg_funcs(32, RCC_CFGR_PLLSRC,   15, 2)
bf_reg_funcs(32, RCC_CFGR_PPRE2,    11, 3)
bf_reg_funcs(32, RCC_CFGR_PPRE1,     8, 3)
bf_reg_funcs(32, RCC_CFGR_HPRE,      4, 4)
bf_reg_funcs(32, RCC_CFGR_SWS,       2, 2)
bf_reg_funcs(32, RCC_CFGR_SW,        0, 2)

inline volatile uint32_t *
RCC_CFGR() {
  return RCC_REG(0x4);
}

bf_reg_funcs(8, RCC_CIR_CSS, 7, 1)
bf_reg_funcs(8, RCC_CIR_PLL, 4, 1)
bf_reg_funcs(8, RCC_CIR_HSE, 3, 1)
bf_reg_funcs(8, RCC_CIR_HSI, 2, 1)
bf_reg_funcs(8, RCC_CIR_LSE, 1, 1)
bf_reg_funcs(8, RCC_CIR_LSI, 0, 1)

inline volatile uint8_t *
RCC_CIR_RDYF() {
  return RCC_REG8(0x8);
}

inline volatile uint8_t *
RCC_CIR_RDYIE() {
  return RCC_REG8(0x9);
}

inline volatile uint8_t *
RCC_CIR_RDYC() {
  return RCC_REG8(0x10);
}

bf_reg_funcs(32, RCC_APB2RSTR_TIM20, 20, 1)
bf_reg_funcs(32, RCC_APB2RSTR_TIM17, 18, 1)
bf_reg_funcs(32, RCC_APB2RSTR_TIM16, 17, 1)
bf_reg_funcs(32, RCC_APB2RSTR_TIM15, 16, 1)
bf_reg_funcs(32, RCC_APB2RSTR_SPI4,  15, 1)
bf_reg_funcs(32, RCC_APB2RSTR_USART1,14, 1)
bf_reg_funcs(32, RCC_APB2RSTR_TIM8,  13, 1)
bf_reg_funcs(32, RCC_APB2RSTR_SPI1,  12, 1)
bf_reg_funcs(32, RCC_APB2RSTR_TIM1,  11, 1)
bf_reg_funcs(32, RCC_APB2RSTR_SYSCFG, 0, 1)

inline volatile uint32_t *
RCC_APB2RSTR() {
  return RCC_REG(0xC);
}

bf_reg_funcs(32, RCC_APB1RSTR_I2C3, 30, 1)
bf_reg_funcs(32, RCC_APB1RSTR_DAC1, 29, 1)
bf_reg_funcs(32, RCC_APB1RSTR_PWR,  28, 1)
bf_reg_funcs(32, RCC_APB1RSTR_DAC2, 26, 1)
bf_reg_funcs(32, RCC_APB1RSTR_CAN,  25, 1)
bf_reg_funcs(32, RCC_APB1RSTR_USB,  23, 1)
bf_reg_funcs(32, RCC_APB1RSTR_I2C2, 22, 1)
bf_reg_funcs(32, RCC_APB1RSTR_I2C1, 21, 1)
bf_reg_funcs(32, RCC_APB1RSTR_UART5,20, 1)
bf_reg_funcs(32, RCC_APB1RSTR_UART4,19, 1)
bf_reg_funcs(32, RCC_APB1RSTR_UART3,18, 1)
bf_reg_funcs(32, RCC_APB1RSTR_UART2,17, 1)
bf_reg_funcs(32, RCC_APB1RSTR_SPI3, 15, 1)
bf_reg_funcs(32, RCC_APB1RSTR_SPI2, 14, 1)
bf_reg_funcs(32, RCC_APB1RSTR_WWDG, 11, 1)
bf_reg_funcs(32, RCC_APB1RSTR_TIM17, 5, 1)
bf_reg_funcs(32, RCC_APB1RSTR_TIM6,  4, 1)
bf_reg_funcs(32, RCC_APB1RSTR_TIM4,  2, 1)
bf_reg_funcs(32, RCC_APB1RSTR_TIM3,  1, 1)
bf_reg_funcs(32, RCC_APB1RSTR_TIM2,  0, 1)

inline volatile uint32_t *
RCC_APB1RSTR() {
  return RCC_REG(0x10);
}

bf_reg_funcs(32, RCC_AHBENR_ADC34, 29, 1)
bf_reg_funcs(32, RCC_AHBENR_ADC12, 28, 1)
bf_reg_funcs(32, RCC_AHBENR_TSEN,  24, 1)
bf_reg_funcs(32, RCC_AHBENR_IOPG,  23, 1)
bf_reg_funcs(32, RCC_AHBENR_IOPF,  22, 1)
bf_reg_funcs(32, RCC_AHBENR_IOPE,  21, 1)
bf_reg_funcs(32, RCC_AHBENR_IOPD,  20, 1)
bf_reg_funcs(32, RCC_AHBENR_IOPC,  19, 1)
bf_reg_funcs(32, RCC_AHBENR_IOPB,  18, 1)
bf_reg_funcs(32, RCC_AHBENR_IOPA,  17, 1)
bf_reg_funcs(32, RCC_AHBENR_IOPH,  16, 1)
bf_reg_funcs(32, RCC_AHBENR_CRC,    6, 1)
bf_reg_funcs(32, RCC_AHBENR_FMC,    5, 1)
bf_reg_funcs(32, RCC_AHBENR_FLITF,  4, 1)
bf_reg_funcs(32, RCC_AHBENR_SRAM,   2, 1)
bf_reg_funcs(32, RCC_AHBENR_DMA2,   1, 1)
bf_reg_funcs(32, RCC_AHBENR_DMA1,   0, 1)

inline volatile uint32_t *
RCC_AHBENR() {
  return RCC_REG(0x14);
}

bf_reg_funcs(32, RCC_APB2ENR_TIM20, 20, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM17, 18, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM16, 17, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM15, 16, 1)
bf_reg_funcs(32, RCC_APB2ENR_SPI4,  15, 1)
bf_reg_funcs(32, RCC_APB2ENR_USART, 14, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM8,  13, 1)
bf_reg_funcs(32, RCC_APB2ENR_SPI1,  12, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM1,  11, 1)
bf_reg_funcs(32, RCC_APB2ENR_SYSCFG, 0, 1)

inline volatile uint32_t *
RCC_APB2ENR() {
  return RCC_REG(0x18);
}

bf_reg_funcs(32, RCC_APB2ENR_I2C3, 30, 1)
bf_reg_funcs(32, RCC_APB2ENR_DAC1, 29, 1)
bf_reg_funcs(32, RCC_APB2ENR_PWR,  28, 1)
bf_reg_funcs(32, RCC_APB2ENR_DAC2, 26, 1)
bf_reg_funcs(32, RCC_APB2ENR_CAN,  25, 1)
bf_reg_funcs(32, RCC_APB2ENR_USB,  23, 1)
bf_reg_funcs(32, RCC_APB2ENR_I2C2, 22, 1)
bf_reg_funcs(32, RCC_APB2ENR_I2C1, 21, 1)
bf_reg_funcs(32, RCC_APB2ENR_UART5,20, 1)
bf_reg_funcs(32, RCC_APB2ENR_UART4,19, 1)
bf_reg_funcs(32, RCC_APB2ENR_UART3,18, 1)
bf_reg_funcs(32, RCC_APB2ENR_UART2,17, 1)
bf_reg_funcs(32, RCC_APB2ENR_SPI3, 15, 1)
bf_reg_funcs(32, RCC_APB2ENR_SPI2, 14, 1)
bf_reg_funcs(32, RCC_APB2ENR_WWDG, 11, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM7,  5, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM6,  4, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM4,  2, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM3,  1, 1)
bf_reg_funcs(32, RCC_APB2ENR_TIM2,  0, 1)

inline volatile uint32_t *
RCC_APB1ENR() {
  return RCC_REG(0x1C);
}

enum {

  RCC_BDCR_RTCSEL_NOCLK = 0,
  RCC_BDCR_RTCSEL_LSE   = 1,
  RCC_BDCR_RTCSEL_LSI   = 2,
  RCC_BDCR_RTCSEL_HSE   = 3,

  RCC_BDCR_LSEDRV_LOW    = 0,
  RCC_BDCR_LSEDRV_MIDLOW = 1,
  RCC_BDCR_LSEDRV_MIDHIGH= 2,
  RCC_BDCR_LSEDRV_HIGH   = 3

};

bf_reg_funcs(32, RCC_BDCR_BDRST, 16, 1)
bf_reg_funcs(32, RCC_BDCR_RTCEN, 15, 1)
bf_reg_funcs(32, RCC_BDCR_RTCSEL, 8, 2)
bf_reg_funcs(32, RCC_BDCR_LSEDRV, 3, 2)
bf_reg_funcs(32, RCC_BDCR_LSEBYP, 2, 1)
bf_reg_funcs(32, RCC_BDCR_LSERDY, 1, 1)
bf_reg_funcs(32, RCC_BDCR_LSEON,  0, 1)

inline volatile uint32_t *
RCC_BDCR() {
  return RCC_REG(0x20);
}

bf_reg_funcs(32, RCC_CSR_LPWRRSTF,  31, 1)
bf_reg_funcs(32, RCC_CSR_WWDGRSTF,  30, 1)
bf_reg_funcs(32, RCC_CSR_IWWDGRSTF, 29, 1)
bf_reg_funcs(32, RCC_CSR_SFTRSTF,   28, 1)
bf_reg_funcs(32, RCC_CSR_PORRSTF,   27, 1)
bf_reg_funcs(32, RCC_CSR_PINRSTF,   26, 1)
bf_reg_funcs(32, RCC_CSR_OBLRSTF,   25, 1)
bf_reg_funcs(32, RCC_CSR_RMVF,      24, 1)
bf_reg_funcs(32, RCC_CSR_V18PWrRSTF,23, 1)
bf_reg_funcs(32, RCC_CSR_LSIRDY,     1, 1)
bf_reg_funcs(32, RCC_CSR_LSION,      0, 1)

inline volatile uint32_t *
RCC_CSR() {
  return RCC_REG(0x24);
}

inline volatile uint8_t *
RCC_CSR_LSION() {
  return RCC_REG8(0x24);
}

bf_reg_funcs(32, RCC_AHBRSTR_ADC34RST, 29, 1)
bf_reg_funcs(32, RCC_AHBRSTR_ADC12RST, 28, 1)
bf_reg_funcs(32, RCC_AHBRSTR_TSCRST,   24, 1)
bf_reg_funcs(32, RCC_AHBRSTR_IOPGRST,  23, 1)
bf_reg_funcs(32, RCC_AHBRSTR_IOPFRST,  22, 1)
bf_reg_funcs(32, RCC_AHBRSTR_IOPERST,  21, 1)
bf_reg_funcs(32, RCC_AHBRSTR_IOPDRST,  20, 1)
bf_reg_funcs(32, RCC_AHBRSTR_IOPCRST,  19, 1)
bf_reg_funcs(32, RCC_AHBRSTR_IOPBRST,  18, 1)
bf_reg_funcs(32, RCC_AHBRSTR_IOPARST,  17, 1)
bf_reg_funcs(32, RCC_AHBRSTR_IOPHRST,  16, 1)
bf_reg_funcs(32, RCC_AHBRSTR_FMCRST,    5, 1)

inline volatile uint32_t *
RCC_AHBRSTR() {
  return RCC_REG(0x28);
}

enum {

  RCC_CFGR2_PRES_DIV1   = 16,
  RCC_CFGR2_PRES_DIV2   = 17,
  RCC_CFGR2_PRES_DIV4   = 18,
  RCC_CFGR2_PRES_DIV6   = 19,
  RCC_CFGR2_PRES_DIV8   = 20,
  RCC_CFGR2_PRES_DIV10  = 21,
  RCC_CFGR2_PRES_DIV12  = 22,
  RCC_CFGR2_PRES_DIV16  = 23,
  RCC_CFGR2_PRES_DIV32  = 24,
  RCC_CFGR2_PRES_DIV64  = 25,
  RCC_CFGR2_PRES_DIV128 = 26,
  RCC_CFGR2_PRES_DIV256 = 27

};

inline uint8_t
RCC_CFGR2_PREDIV(uint8_t div) {
  return div - 1;
}

bf_reg_funcs(16, RCC_CFGR2_ADC34PRES, 9, 5)
bf_reg_funcs(16, RCC_CFGR2_ADC12PRES, 4, 5)
bf_reg_funcs(16, RCC_CFGR2_PREDIV,    0, 4)

inline volatile uint16_t *
RCC_CFGR2() {
  return RCC_REG16(0x2C);
}

enum {

  RCC_CFGR3_TIMSW_PCLK = 0,
  RCC_CFGR3_TIMSW_PLL  = 1,

  RCC_CFGR3_UARTSW_PCLK   = 0,
  RCC_CFGR3_UARTSW_SYSCLK = 1,
  RCC_CFGR3_UARTSW_LSE    = 2,
  RCC_CFGR3_UARTSW_HSI    = 3,

  RCC_CFGR3_I2CSW_HSI    = 0,
  RCC_CFGR3_I2CSW_SYSCLK = 1

};

bf_reg_funcs(32, RCC_CFGR3_TIM34SW, 25, 1)
bf_reg_funcs(32, RCC_CFGR3_TIM2SW,  24, 1)
bf_reg_funcs(32, RCC_CFGR3_UART5SW, 22, 2)
bf_reg_funcs(32, RCC_CFGR3_UART4SW, 20, 2)
bf_reg_funcs(32, RCC_CFGR3_UART3SW, 18, 2)
bf_reg_funcs(32, RCC_CFGR3_UART2SW, 16, 2)
bf_reg_funcs(32, RCC_CFGR3_TIM20SW, 15, 1)
bf_reg_funcs(32, RCC_CFGR3_TIM17SW, 13, 1)
bf_reg_funcs(32, RCC_CFGR3_TIM16SW, 11, 1)
bf_reg_funcs(32, RCC_CFGR3_TIM15SW, 10, 1)
bf_reg_funcs(32, RCC_CFGR3_TIM8SW,   9, 1)
bf_reg_funcs(32, RCC_CFGR3_TIM1SW,   8, 1)
bf_reg_funcs(32, RCC_CFGR3_I2C3SW,   6, 1)
bf_reg_funcs(32, RCC_CFGR3_I2C2SW,   5, 1)
bf_reg_funcs(32, RCC_CFGR3_I2C1SW,   4, 1)
bf_reg_funcs(32, RCC_CFGR3_USART1SW, 2, 2)


inline volatile uint32_t *
RCC_CFGR3() {
  return RCC_REG(0x30);
}

#endif /* _STM32F3_RCC_H */
