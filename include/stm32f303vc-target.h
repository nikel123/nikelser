#ifndef _DEFAULT_LAYOUT_H
#define _DEFAULT_LAYOUT_H

/* stm32f303vc linker script
 * (c) Andrej Gelenberg <andrej.gelenberg@udo.edu> 2013
 */

#include <stdint.h>
#include <stddef.h>

extern const uint32_t
vtable_src[];

extern uint32_t
vtable_dst[];

extern uint32_t
vtable_end[];


extern const uint32_t
text_ccm_src[];

extern uint32_t
text_ccm_dst[];

extern uint32_t
text_ccm_end[];


extern uint32_t
data_dst[];

extern const uint32_t
data_src[];

extern uint32_t
data_end[];


extern uint32_t
bss_start[];

extern uint32_t
bss_end[];


extern uint32_t
stack_start[];

#endif // _DEFAULT_LAYOUT_H
