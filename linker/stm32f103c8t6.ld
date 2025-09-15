/* STM32F103C8T6 Linker Script */
/* Flash size: 64KB, SRAM: 20KB */

ENTRY(Reset_Handler)

/* Define memory regions */
MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 64K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

/* Sections */
SECTIONS
{
  /* Vector Table + Code */
  .text :
  {
    KEEP(*(.isr_vector))   /* Interrupt vector table */
    *(.text*)              /* Program code */
    *(.rodata*)            /* Read-only data */
    KEEP(*(.init))
    KEEP(*(.fini))
  } > FLASH

  /* Initialized data goes to RAM, load from Flash */
  .data : AT (ADDR(.text) + SIZEOF(.text))
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > RAM

  /* Uninitialized data (zero-initialized) */
  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  /* Stack setup at end of RAM */
  ._user_stack (NOLOAD):
  {
    . = ALIGN(8);
    _estack = ORIGIN(RAM) + LENGTH(RAM);
  } > RAM
}

/* Symbols for startup code */
PROVIDE(_sidata = LOADADDR(.data));
PROVIDE(_sdata  = ADDR(.data));
PROVIDE(_edata  = ADDR(.data) + SIZEOF(.data));
PROVIDE(_sbss   = ADDR(.bss));
PROVIDE(_ebss   = ADDR(.bss) + SIZEOF(.bss));
PROVIDE(_estack = ORIGIN(RAM) + LENGTH(RAM));
