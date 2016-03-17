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
int
main() {

  int i;
  volatile register int j;

  *RCC_AHBENR() =
      RCC_AHBENR_IOPE_val(1)
    | RCC_AHBENR_SRAM_val(1)
    | RCC_AHBENR_FLITF_val(1)
    ;

  *gpio_e_moder() =
      gpioinit(gpio_moder_val, GPIO_MODE_OUT);

  *gpio_e_otyper() =
      gpioinit(gpio_otyper_val, 0);

  *gpio_e_ospeedr() =
      gpioinit(gpio_ospeedr_val,GPIO_OSPEED_HI);

  *gpio_e_pupdr() =
      gpioinit(gpio_pupdr_val, GPIO_PULL_NONE);


  while(1) {

    for(i = 0; i < 7; ++i) {
      *gpio_e_odr() = 1 << (8 + i);
      for(j = 0; j < 100000; ++j);
    }

  }

}
