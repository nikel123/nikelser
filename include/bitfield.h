#ifndef _BITFIELD_H
#define _BITFIELD_H

#include <stdint.h>

#define bf_type(bits) uint ## bits ## _t
#define bf_func_name(bits, name) bf ## bits ## _ ## name

// return bit pattern of 'width' 1's
#define bf_val_mask(bits, width) \
  bf_func_name(bits, val_mask)(width)

// return bit pattern of 'width' 1's at bit offset of 'offset'
#define bf_mask(bits, offset, width) \
  bf_func_name(bits, mask)(offset, width)

// return value with set fitfield value
#define bf_val(bits, vval, offset, width) \
  bf_func_name(bits, val)(vval, offset, width)

// return value of the bit field from 'src'
#define bf_get(bits, src, offset, width) \
  bf_func_name(bits, get)(src, offset, width)

// return 'src' with set bitfield value
#define bf_set(bits, src, val, offset, width) \
  bf_func_name(bits, set)(src, val, offset, width)

#define bf_type_bits 8
#include <bitfield_defs.h>

#define bf_type_bits 16
#include <bitfield_defs.h>

#define bf_type_bits 32
#include <bitfield_defs.h>

#define bf_reg_funcs(bits, name, width, offset) \
  inline uint ## bits ## _t \
  name ## _val_mask() { \
    return bf_val_mask(bits, width); \
  } \
  \
  inline uint ## bits ## _t \
  name ## _mask() { \
    return bf_mask(bits, offset, width); \
  } \
  \
  inline uint ## bits ## _t \
  name ## _val(uint ## bits ## _t val) { \
    return bf_val(bits, val, offset, width);  \
  } \
  \
  inline uint ## bits ## _t \
  name ## _get(uint ## bits ## _t src) { \
    return bf_get(bits, src, offset, width); \
  } \
  \
  inline uint ## bits ## _t \
  name ## _set(uint ## bits ## _t src, uint ## bits ## _t val) {\
    return bf_set(bits, src, val, offset, width); \
  }

#endif /* _BITFIELD_H */
