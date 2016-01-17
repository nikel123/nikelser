#ifndef _BITFIELD_H
#  error "bitfield_defs.h is only for internal use in bitfield.h"
#endif

#ifndef bf_type_bits
#  error "bf_type_bits is undefined"
#endif

#define _bf_def_type(bits) \
  bf_type(bits)

#define bf_def_type \
  _bf_def_type(bf_type_bits)

#define _bf_def_func_name(bits, name) \
  bf_func_name(bits, name)

#define bf_def_func_name(name) \
  _bf_def_func_name(bf_type_bits, name)

/*
 uint<bits>_t
 bf<bits>_value_mask(
     uint8_t width)

  return value bit mask for given width of a bitfield
*/
inline bf_def_type
bf_def_func_name(value_mask)(
    uint8_t width) {
  return (1 << width) - 1;
}

/*
  uint<bits>_t
  bf<bits>_mask(
      uint8_t offset,
      uint8_t width)

  return bitfield bit mask
*/
inline bf_def_type
bf_def_func_name(mask)(
    uint8_t offset,
    uint8_t width) {
  return bf_def_func_name(value_mask)(width) << offset;
}

/*
  uint<bits>_t
  bf<bits>_get(
      uint<bits>_t src,
      uint8_t      offset,
      uint8_t      width)

  extract bitfield value from 'src'
*/
inline bf_def_type
bf_def_func_name(get)(
    bf_def_type src,
    uint8_t     offset,
    uint8_t     width) {
  return (src >> offset) & bf_def_func_name(value_mask)(width);
}

/*
  uint<bits>_t
  bf<bits>_val(
      uint<bits>_t val,
      uint8_t      width,
      uint8_t      offset)

  return value with set bitfield to 'val'
*/
inline bf_def_type
bf_def_func_name(val)(
    bf_def_type val,
    uint8_t     offset,
    uint8_t     width) {
  return (val & bf_def_func_name(value_mask)(width)) << offset;
}

/*
  uint<bits>_t
  bf<bits>_set(
      uint<bits>_t src,
      uint<bits>_t val,
      uint8_t      offset,
      uint8_t      width)

  set bitfield of 'src' to 'val' and return the result
*/
inline bf_def_type
bf_def_func_name(set)(
    bf_def_type src,
    bf_def_type val,
    uint8_t     offset,
    uint8_t     width) {
  return
      (src & ~bf_def_func_name(mask)(offset, width)) |
      bf_def_func_name(val)(val,offset,width);
}

#undef bf_def_type
#undef _bf_def_type
#undef bf_def_func_name
#undef _bf_def_func_name
#undef bf_type_bits
