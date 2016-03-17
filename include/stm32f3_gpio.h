#ifndef _STM32F3_GPIO_H
#define _STM32F3_GPIO_H

#include <stdint.h>
#include <bitfield.h>

#define GPIO_NAME(idx, name) GPIO ## idx ## _ ## name

enum {
  GPIO_OSPEED_LOW = 0,
  GPIO_OSPEED_MED = 1,
  GPIO_OSPEED_HI  = 3
};

enum {
  GPIO_MODE_IN     = 0,
  GPIO_MODE_OUT    = 1,
  GPIO_MODE_ALT    = 2,
  GPIO_MODE_ANALOG = 3
};

enum {
  GPIO_PULL_NONE = 0,
  GPIO_PULL_UP   = 1,
  GPIO_PULL_DOWN = 2
};

#define gpio_2bit_funcs(regname) \
  inline uint32_t \
  gpio_ ## regname ## _val_mask() { \
    return bf32_val_mask(2); \
  } \
  \
  inline uint32_t \
  gpio_ ## regname ## _mask(uint8_t i) { \
    return bf32_mask(2*i, 2); \
  } \
  \
  inline uint32_t \
  gpio_ ## regname ## _val(uint8_t val, uint8_t i) { \
    return bf32_val(val, 2*i, 2); \
  } \
  \
  inline uint8_t \
  gpio_ ## regname ## _get(uint32_t src, uint8_t i) { \
    return bf32_get(src, 2*i, 2); \
  } \
  \
  inline uint32_t \
  gpio_ ## regname ## _set(uint32_t src, uint8_t val, uint8_t i) { \
    return bf32_set(src, val, 2*i, 2); \
  }

#define gpio_1bit_funcs(regname) \
  inline uint32_t \
  gpio_ ## regname ## _val_maks() { \
    return bf32_val_mask(1); \
  } \
  \
  inline uint32_t \
  gpio_ ## regname ## _mask(uint8_t i) { \
    return bf32_mask(i, 1); \
  } \
  \
  inline uint32_t \
  gpio_ ## regname ## _val(uint8_t val, uint8_t i) { \
    return bf32_val(val, i, 1); \
  } \
  \
  inline uint8_t \
  gpio_ ## regname ## _get(uint32_t src, uint8_t i) { \
    return bf32_get(src, i, 1); \
  } \
  \
  inline uint32_t \
  gpio_ ## regname ## _set(uint32_t src, uint8_t val, uint8_t i) { \
    return bf32_set(src, val, i, 1); \
  }

#define gpio_reg_funcs(letter, num) \
  inline volatile void * \
  gpio_ ## letter ## _base() { \
    return gpio_base(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _moder() { \
    return gpio_moder(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _otyper() { \
    return gpio_otyper(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _ospeedr() { \
    return gpio_ospeedr(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _pupdr() { \
    return gpio_pupdr(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _idr() { \
    return gpio_idr(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _odr() { \
    return gpio_odr(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _bsrr() { \
    return gpio_bsrr(num) ; \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _lockr() { \
    return gpio_lockr(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _afrl() { \
    return gpio_afrl(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _afrh() { \
    return gpio_afrh(num); \
  } \
  \
  inline volatile uint32_t * \
  gpio_ ## letter ## _brr() { \
    return gpio_brr(num); \
  }

inline volatile void *
gpio_base(uint8_t n) {
  return (void *)0x48000000 + 0x400 * n;
}

inline volatile uint32_t *
gpio_moder(uint8_t n) {
  return (volatile uint32_t *)gpio_base(n);
}

gpio_2bit_funcs(moder)

inline volatile uint32_t *
gpio_otyper(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0x4);
}

gpio_1bit_funcs(otyper)

inline volatile uint32_t *
gpio_ospeedr(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0x8);
}

gpio_2bit_funcs(ospeedr)

inline volatile uint32_t *
gpio_pupdr(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0xc);
}

gpio_2bit_funcs(pupdr)

inline volatile uint32_t *
gpio_idr(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0x10);
}

gpio_1bit_funcs(idr)

inline volatile uint32_t *
gpio_odr(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0x14);
}

gpio_1bit_funcs(odr)

inline volatile uint32_t *
gpio_bsrr(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0x18);
}

gpio_1bit_funcs(bsrr)

inline volatile uint32_t *
gpio_lockr(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0x1c);
}

bf_reg_funcs(32, gpio_lockr_lckk, 16, 1)

inline uint32_t
gpio_lockr_val_mask() {
  return bf32_val_mask(1);
}

inline uint32_t
gpio_lockr_mask(uint8_t i) {
  return bf32_mask(i, 1);
}

inline uint32_t
gpio_lockr_val(uint8_t val, uint8_t i) {
  return bf32_val(val, i, 1);
}

inline uint32_t
gpio_lockr_get(uint32_t src, uint8_t i) {
  return bf32_get(src, i, 1);
}

inline uint32_t
gpio_lockr_set(uint32_t src, uint8_t val, uint8_t i) {
  return bf32_set(src, val, i, 1);
}

inline volatile uint32_t *
gpio_afrl(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0x20);
}

inline uint32_t
gpio_afrl_val_mask() {
  return bf32_val_mask(4);
}

inline uint32_t
gpio_afrl_mask(uint8_t i) {
  return bf32_mask(4*i, 4);
}

inline uint32_t
gpio_afrl_val(uint8_t val, uint8_t i) {
  return bf32_val(val, 4*i, 4);
}

inline uint32_t
gpio_afrl_get(uint32_t src, uint8_t i) {
  return bf32_get(src, 4*i, 4);
}

inline uint32_t
gpio_afrl_set(uint32_t src, uint8_t val, uint8_t i) {
  return bf32_set(src, val, 4*i, 4);
}

inline volatile uint32_t *
gpio_afrh(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0x24);
}

inline uint32_t
gpio_afrh_val_mask() {
  return bf32_val_mask(4);
}

inline uint32_t
gpio_afrh_mask(uint8_t i) {
  return bf32_mask(4*(i-8), 4);
}

inline uint32_t
gpio_afrh_val(uint8_t val, uint8_t i) {
  return bf32_val(val, 4*(i-8), 4);
}

inline uint32_t
gpio_afrh_get(uint32_t val, uint8_t i) {
  return bf32_get(val, 4*(i-8), 4);
}

inline uint32_t
gpio_afrh_set(uint32_t src, uint8_t val, uint8_t i) {
  return bf32_set(src, val, 4*(i-8), 4);
}

inline volatile uint32_t *
gpio_brr(uint8_t n) {
  return (volatile uint32_t *)(gpio_base(n) + 0x28);
}

gpio_1bit_funcs(brr)

gpio_reg_funcs(a, 0)
gpio_reg_funcs(b, 1)
gpio_reg_funcs(c, 2)
gpio_reg_funcs(d, 3)
gpio_reg_funcs(e, 4)
gpio_reg_funcs(f, 5)
gpio_reg_funcs(h, 6)

#endif // _STM32F3_GPIO_H
