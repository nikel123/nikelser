.fpu softvfp
.thumb

.global stack_size
.global vtable

.macro def_isr name
  .word \name\()_ISR
  .weak \name\()_ISR
  .thumb_set \name\()_ISR, 0
.endm

.section .vtable,"a",%progbits

  .type vtable, %object

vtable:
  .word stack_start

  .word Reset_ISR

  .irp i, NMI, HardFault, MemManage, BusFault, UsageFault
    def_isr \i
  .endr

  .skip 4 * 4, 0

  .irp i, VSCall, DebugMon
    def_isr \i
  .endr

  .skip 4, 0

  .irp i, PandSV, SysTick
    def_isr \i
  .endr

  /* IRQ */
  .irp i, WWDG, PVD, TAMP_STAMP, RTC_WKUP, FLASH, RCC, EXTI0, EXTI1, EXTI2_TSC, EXTI3, EXTI4
    def_isr \i
  .endr

  .irpc i, 1234567
    def_isr DMA1_CH\i
  .endr

  .irp i, ADC1_2, USB_HP_CAN_TX, USB_LP_CAN_RX0, CAN_RX1, CAN_SCE, EXTI9_5, TIM1_BRK1_TIM15, TIM1_UP_TIM16, TIM1_TRG_COM_TIM17, TIM1_CC
    def_isr \i
  .endr

  .irpc i, 234
    def_isr TIM\i
  .endr

  .irp i, I2C1_EV_EXTI23, I2C1_ER, I2C2_EV_EXTI24, I2C2_ER, SPI1, SPI2, UART1_EXTI25, URAT2_EXTI26, UART3_EXTI28, EXTI15_10, RTCAlarm, USB_WKUP, TIM8_BRK, TIM8_UP, TIM8_TRG_COM, TIM8_CC, ADC3
    def_isr \i
  .endr

  .skip 3 * 4, 0

  .irp i, SPI3, UART4_EXTI34, UART5_EXTI35, TIM6_DACUNDER, TIM7
    def_isr \i
  .endr

  .irpc i, 12345
    def_isr DMA2_CH\i
  .endr

  def_isr ADC4

  .skip 2 * 4, 0

  .irp i, COMP123, COMP456, COMP7
    def_isr \i
  .endr

  .skip 7 * 4, 0

  .irp i, USB_HP, USB_LP, USB_WKUP
    def_isr \i
  .endr

  .skip 4 * 4, 0

  def_isr FPU

 .size vtable, . - vtable

/* END OF VECTOR TABLE */
