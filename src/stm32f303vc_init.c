#include <stm32f303vc.h>
#include <stm32f3_rcc.h>

#include "utils.h"

#define clock_cfg ( \
    RCC_CFGR_MCO_val(RCC_CFGR_MCO_PLL)        | \
    RCC_CFGR_PLLMUL_val(RCC_CFGR_PLLMUL_x6)   | \
    RCC_CFGR_PLLSRC_val(RCC_CFGR_PLLSRC_HSE)  | \
    RCC_CFGR_PPRE1_val(RCC_CFGR_PPRE_DIV2) )

extern void
main() __attribute__((noreturn));

static void
cinit() {

  // relocate .text.ccm
  memmove32(
      text_ccm_dst,
      text_ccm_end,
      text_ccm_src);

  // relocate .data
  memmove32(
      data_dst,
      data_end,
      data_src);

  // init bss section
  meminit32(
      bss_start,
      bss_end,
      0);

}

static void
vtable_relocation() {

  // relocate vector table
  memmove32(
      vtable_dst,
      vtable_end,
      vtable_src);

  *SCB_VTOR() = vtable_dst;

}

extern volatile int rcc_isr_f;

void
RCC_ISR() {

  if ( *RCC_CIR_RDYF() & RCC_CIR_HSE_mask() ) {
    *RCC_CIR_RDYC()  = RCC_CIR_HSE_val(1);
    *RCC_CIR_RDYIE() = RCC_CIR_PLL_val(1);
    *RCC_PLL()       = RCC_PLL_ON_val(1);
  }

  if ( *RCC_CIR_RDYF() & RCC_CIR_PLL_mask() ) {
    *RCC_CIR_RDYC()  = RCC_CIR_PLL_val(1);
    *RCC_CFGR() =
      clock_cfg | RCC_CFGR_SW_val(RCC_CFGR_SW_PLL);
    if ( *RCC_PLL() & RCC_PLL_RDY_mask() )
      rcc_isr_f = 1;
    *RCC_CIR_RDYIE() = 0;
  }

}

static void
init_clocks() {

 *RCC_CFGR() = clock_cfg;
 NVIC_enable(5);
 *RCC_CIR_RDYIE() = RCC_CIR_HSE_val(1);
 *RCC_HSE() = RCC_HSE_ON_val(1) | RCC_HSE_BYP_val(1);

}

void __attribute__((noreturn))
Reset_ISR() {

  init_clocks();
  cinit();
  vtable_relocation();
  main();

}
