#include <armv7m.h>
#include <stm32f3_gpio.h>

int
main() {

  register volatile int i;

  register volatile uint8_t *r = ((volatile uint8_t *)gpio_e_odr()) + 1;

  *(((volatile uint16_t *)gpio_e_moder()) + 1) =
      bf16_val(GPIO_MODE_OUT,  0, 2) |
      bf16_val(GPIO_MODE_OUT,  2, 2) |
      bf16_val(GPIO_MODE_OUT,  4, 2) |
      bf16_val(GPIO_MODE_OUT,  6, 2) |
      bf16_val(GPIO_MODE_OUT,  8, 2) |
      bf16_val(GPIO_MODE_OUT, 10, 2) |
      bf16_val(GPIO_MODE_OUT, 12, 2) |
      bf16_val(GPIO_MODE_OUT, 14, 2);

  while(1) {

    *r = 1;

    for(i=0; i < 1000000; ++i);

    *r = 0;

    for(i=0; i < 1000000; ++i);

  }

}
