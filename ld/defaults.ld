stack_size = 512;
msp_stack_size = stack_size;
psp_stack_size = stack_size;

REGION_ALIAS("VTABLEMEM", FLASH)
REGION_ALIAS("TEXTMEM",   FLASH)
REGION_ALIAS("ROMEM",     FLASH)
