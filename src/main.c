#include <armv7m.h>
#include <stm32f3_gpio.h>
#include <stm32f3_rcc.h>

#define gpioinit(f, val) \
      f(val,  0) | \
      f(val,  1) | \
      f(val,  2) | \
      f(val,  3) | \
      f(val,  4) | \
      f(val,  5) | \
      f(val,  6) | \
      f(val,  7) | \
      f(val,  8) | \
      f(val,  9) | \
      f(val, 10) | \
      f(val, 11) | \
      f(val, 12) | \
      f(val, 13) | \
      f(val, 14) | \
      f(val, 15)

volatile int rcc_isr_f = 0;

int
main() {

  int i = 1;
  register volatile int j;
  uint32_t v;

  *RCC_AHBENR() =
      RCC_AHBENR_IOPA_val(1)
    | RCC_AHBENR_IOPE_val(1)
    | RCC_AHBENR_SRAM_val(1)
    | RCC_AHBENR_FLITF_val(1)
    ;


  *gpio_a_moder() =
    gpio_moder_set(*gpio_a_moder(), GPIO_MODE_ALT,  8);

  *gpio_a_ospeedr() =
    gpio_otyper_set(
      *gpio_a_ospeedr(),
      GPIO_OSPEED_HI,
      8);

  *gpio_a_pupdr() =
    gpio_pupdr_set(
      *gpio_a_pupdr(),
      GPIO_PULL_UP,
      8);

  *gpio_e_moder() =
      gpioinit(gpio_moder_val, GPIO_MODE_OUT);

  *gpio_e_ospeedr() =
      gpioinit(gpio_ospeedr_val,GPIO_OSPEED_HI);


  while(1) {

    v = 0;

    if ( i ) {
      i = 0;
    } else {
      v |= 1 << 8;
      i = 1;
    }

    if ( !rcc_isr_f || i ) {
      v |= 1 << 9;
    }

    *gpio_e_odr() = v;

    for(j = 0; j < 1000000; ++j);

  }

}
