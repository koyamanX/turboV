OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS
{
  . = 0x80000000;
  .text.init : { *(.text.init) }
  .text : { *(.text) }
  . = ALIGN(0x1000);
  .rodata : { *(.rodata) }
  . = ALIGN(0x1000);
  .sdata : { *(.sdata) }
  .data : { *(.data) }
  . = ALIGN(0x1000);
  _bss_start = .;
  .bss : { *(.bss) }
  .sbss : { *(.sbss) }
  . = ALIGN(0x1000);
  _bss_end = .;
  . = ALIGN(0x1000);
  _heap_start = .;
  . = ALIGN(0x1000);
  . = . + 0x02000000;
  . = ALIGN(0x1000);
  _heap_end = .;
  . = 0x84000000;
  _stack_top = .;
}

