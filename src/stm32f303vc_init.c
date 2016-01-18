#include <stm32f303vc.h>

extern void
main() __attribute__((noreturn));

static void
low_level_init() {

}

static void
cinit() {

  register size_t i;

  // relocate .text.ccm
  for(i = 0; i < text_ccm_size / sizeof(text_ccm_dst[0]); ++i) {

    text_ccm_dst[i] = text_ccm_src[i];

  }

  // relocate .data
  for(i = 0; i < data_size / sizeof(data_dst[0]); ++i) {

    data_dst[i] = data_src[i];

  }

  // init bss section
  for(i = 0; i < bss_size / sizeof(bss_start[0]); ++i) {

    bss_start[i] = 0;

  }

}

static void
vtable_relocation() {

  register uint32_t *s;
  register uint32_t *d;

  // relocate vector table
  for(s = vtable_ccm_src, d = vtable_ccm_dst; d < vtable_ccm_end; ++s, ++d) {

    *s = *d;

  }

  SCB_VTOR = vtable_ccm_dst;

}


void __attribute__((noreturn))
Reset_ISR() {

  low_level_init();
  cinit();
  vtable_relocation();
  main();

}
