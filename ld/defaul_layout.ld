/* stm32f303vc linker script
 * (c) Andrej Gelenberg <andrej.gelenberg@udo.edu> 2013
 */

ENTRY(Reset_ISR)

SECTIONS {

  .vtable : ALIGN(512) {
    KEEP(*(.isr_vector))
  } > VTABLEMEM

  .text : ALIGN(4) {
    *(.text)
    *(.text*)
  } > TEXTMEM

  .rodata : {
    *(.rodata)
    *(.rodata*)
  } > ROMEM

  .data : ALIGN(4) {
    *(.data)
    *(.dada*)
  } > RAM

  .bss : ALIGN(4) {
    _bss_start = .;
    *(.bss)
    . = ALIGN(4);
    _bss_end = .;
  } > RAM

  .heap : ALIGN(4) {
    _user_heap = .;
    . = ORIGIN(RAM) + LENGTH(RAM) - _msp_stack_size - _psp_stack_size;
  } > RAM

  .stack : ALIGN(4) {
    . = ALIGN(32);
    . = . + _psp_stack_size;
		_psp_base = . - 4;
    . = ALIGN(32);
    . = . + _msp_stack_size;
    _msp_base = . - 4;
  } RAM

}
