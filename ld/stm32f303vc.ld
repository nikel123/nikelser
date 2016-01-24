/*
 * (c) Andrej Gelenberg <andrej.gelenberg@udo.edu> 2013-2016
 */

OUTPUT_FORMAT(elf32-littlearm)
OUTPUT_ARCH(arm)

stack_size = 1024;

ENTRY(Reset_ISR)

MEMORY {
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 256K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 40K
  CCM   (rwx) : ORIGIN = 0x10000000, LENGTH = 8K
}

SECTIONS {

  .vtable : ALIGN(512) {

    vtable_src = LOADADDR(.vtable);
    vtable_dst = .;

    KEEP(*(.vtable))

    . = ALIGN(4);
    vtable_end = .;

  } >CCM AT>FLASH


  .text.ccm : {

    text_ccm_src = LOADADDR(.text.ccm);
    text_ccm_dst = .;

    *(.text.ccm)

    . = ALIGN(4);
    text_ccm_end = .;

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
    data_end = .;

  } >RAM AT>FLASH

  .bss : ALIGN(4) {

    bss_start = .;

    *(.bss)
    *(.bss*)

    . = ALIGN(4);
    bss_end = .;

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
