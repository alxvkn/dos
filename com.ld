OUTPUT_FORMAT(binary)
SECTIONS {
    . = 0x100;
    .text : {
        *(.text.startup);
        *(.text);
    }
    .data : {
        *(.data);
        *(.bss);
        *(.rodata);
    }
    _heap = ALIGN(4);
}
