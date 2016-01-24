#include <stm32f303vc.h>

extern void
main() __attribute__((noreturn));

static void
low_level_init() {

}

static void
cinit() {

  uint32_t *s;
  uint32_t *d;

  // relocate .text.ccm
  s = text_ccm_src;
  d = text_ccm_dst;
  while(d < text_ccm_end) {
    *(d++) = *(s++);
  }

  // relocate .data
  s = data_src;
  d = data_dst;
  while(d < data_end) {
    *(d++) = *(s++);
  }

  // init bss section
  d = bss_start;
  while(d < bss_end) {
    *(d++) = 0;
  }


}

static void
vtable_relocation() {

  register uint32_t *s;
  register uint32_t *d;

  // relocate vector table
  s = vtable_src;
  d = vtable_dst;
  while(d < vtable_end) {
    *(d++) = *(s++);
  }

  *SCB_VTOR() = vtable_dst;

}


void __attribute__((noreturn))
Reset_ISR() {

  low_level_init();
  cinit();
  vtable_relocation();
  main();

}
