.word Reset_ISR

.word NMI_ISR
.weak NMI_ISR
.thumb_set NMI_ISR, 0

.word HardFault_ISR
.weak HardFault_ISR
.thumb_set HardFault_ISR, 0

.word MemManage_ISR
.weak MemManage_ISR
.thumb_set MemManage_ISR, 0

.word BusFault_ISR
.weak BusFault_ISR
.thumb_set BusFault_ISR, 0

.word UsageFault_ISR
.weak UsageFault_ISR
.thumb_set UsageFault_ISR, 0

.skip 4 * 4, 0

.word SVCall_ISR
.weak SVCall_ISR
.thumb_set SVCall_ISR, 0

.word DebugMonitor_ISR
.weak DebugMonitor_ISR
.thumb_set DebugMonitor_ISR, 0

.skip 4, 0

.word PendSV_ISR
.weak PendSV_ISR
.thumb_set PendSV_ISR, 0

.word SysTick_ISR
.weak SysTick_ISR
.thumb_set SysTick_ISR, 0
