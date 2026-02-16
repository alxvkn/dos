.code16
.section .text.startup
.global _start

_start:

call _c_startup

mov $0x4c, %ah
int $0x21
