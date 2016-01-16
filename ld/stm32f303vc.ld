/*
 * (c) Andrej Gelenberg <andrej.gelenberg@udo.edu> 2013-2016
 */

INCLUDE stm32f3.ld

MEMORY {
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 256K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 40K
  CCM   (rwx) : ORIGIN = 0x10000000, LENGTH = 8K
}
