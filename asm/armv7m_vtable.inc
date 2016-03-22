.word Reset_ISR

.word NMI_ISR
.weak NMI_ISR

.word HardFault_ISR
.weak HardFault_ISR

.word MemManage_ISR
.weak MemManage_ISR

.word BusFault_ISR
.weak BusFault_ISR

.word UsageFault_ISR
.weak UsageFault_ISR

.skip 4 * 4, 0

.word SVCall_ISR
.weak SVCall_ISR

.word DebugMonitor_ISR
.weak DebugMonitor_ISR

.skip 4, 0

.word PendSV_ISR
.weak PendSV_ISR

.word SysTick_ISR
.weak SysTick_ISR
