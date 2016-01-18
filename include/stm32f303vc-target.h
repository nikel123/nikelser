#ifndef _DEFAULT_LAYOUT_H
#define _DEFAULT_LAYOUT_H

/* stm32f303vc linker script
 * (c) Andrej Gelenberg <andrej.gelenberg@udo.edu> 2013
 */

#include <stdint.h>
#include <stddef.h>

extern uint32_t * const
vtable_ccm_src;

extern uint32_t * const
vtable_ccm_dst;

extern uint32_t * const
vtable_ccm_end;


extern uint32_t * const
text_ccm_src;

extern uint32_t * const 
text_ccm_dst;

extern const size_t
text_ccm_size;


extern uint32_t * const
data_dst;

extern uint32_t * const
data_src;

extern const size_t
data_size;


extern uint32_t * const
bss_start;

extern const size_t
bss_size;


extern const void *
stack_start;

#endif // _DEFAULT_LAYOUT_H
