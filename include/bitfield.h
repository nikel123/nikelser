#ifndef _BITFIELD_H
#define _BITFIELD_H

#include <stdint.h>

#define bf_type(bits) uint ## bits ## _t
#define bf_func_name(bits, name) bf ## bits ## _ ## name

// return bit pattern of 'width' 1's
#define bf_value_mask(bits, width) \
  bf_func_name(bits, value_mask)(width)

// return bit pattern of 'width' 1's at bit offset of 'offset'
#define bf_mask(bits, width, offset) \
  bf_func_name(bits, mask)(width, offset)

// return value with set fitfield value
#define bf_value(bits, width, offset, val) \
  bf_func_name(bits, value)(width, offset, val)

// return value of the bit field from 'src'
#define bf_get(bits, width, offset, src) \
  bf_func_name(bits, get)(width, offset, src)

// return 'src' with set bitfield value
#define bf_set(bits, width, offset, src, val) \
  bf_func_name(bits, set)(width, offset, src, val)

#define bf_type_bits 8
#include <bitfield_defs.h>

#define bf_type_bits 16
#include <bitfield_defs.h>

#define bf_type_bits 32
#include <bitfield_defs.h>

#endif /* _BITFIELD_H */
