#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

inline static void
meminit32(
  uint32_t *dst,
  uint32_t *end,
  uint32_t c) {

  while(dst < end) *(dst++) = c;

}

inline static void
memmove32(
  uint32_t * restrict dst,
  uint32_t *end,
  const uint32_t * restrict src) {

  while(dst < end) {
    *(dst++) = *(src++);
  }

}

#endif // UTILS_H
