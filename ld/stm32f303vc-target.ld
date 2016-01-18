/*
 * (c) Andrej Gelenberg <andrej.gelenberg@udo.edu> 2013-2016
 */

INCLUDE stm32f303vc.ld

stack_size = 1024;

ENTRY(Reset_ISR)

SECTIONS {

  .vtable_ccm : ALIGN(512) {

    vtable_ccm_src = LOADADDR(.vtable_ccm);
    vtable_ccm_dst = .;

    KEEP(*(.vtable_ram))

    . = ALIGN(4);
    vtable_ccm_end = .;

  } >CCM AT>FLASH


  .text.ccm : {

    text_ccm_src = LOADADDR(.text.ccm);
    text_ccm_dst = .;

    *(.text.ccm)

    . = ALIGN(4);
    text_ccm_size = . - text_ccm_dst;

  } >CCM AT>FLASH

  .text : ALIGN(4) {

    *(.text)
    *(.text*)

  } >FLASH


  .rodata : ALIGN(4) {

    *(.rodata)
    *(.rodata*)

  } >FLASH

  .data : ALIGN(4) {

    data_src = LOADADDR(.data);
    data_dst = .;

    *(.data)
    *(.dada*)

    . = ALIGN(4);
    data_size = . - data_dst;

  } >RAM AT>FLASH

  .bss : ALIGN(4) {

    bss_start = .;

    *(.bss)
    *(.bss*)

    . = ALIGN(4);
    bss_size = . - bss_start;

  } >RAM


  .heap : ALIGN(4) {

    heap_start = .;

    . = ORIGIN(RAM) + LENGTH(RAM) - stack_size;

    . = ALIGN(4);
    heap_size = . - heap_start;

  } >RAM

  .stack : ALIGN(4) {

    stack_end = .;

    . = . + stack_size;

    stack_start = .;

  } >RAM

}
