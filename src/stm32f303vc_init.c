#include <stm32f303vc.h>
#include "utils.h"

extern void
main() __attribute__((noreturn));

static void
low_level_init() {

}

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


void __attribute__((noreturn))
Reset_ISR() {

  low_level_init();
  cinit();
  vtable_relocation();
  main();

}
