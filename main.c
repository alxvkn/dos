#include <stdio.h>

__asm__ (
        "call dosmain\n"
        "mov $0x4c, %ah\n"
        "int $0x21\n"
        );

const char* message = "hello msdos!\n";
const unsigned message_length = 12;

void dosmain() {
    puts("hi dos\n");
    for (unsigned i = 0; i < message_length; i++)
        putchar(message[i]);

    return;
}
