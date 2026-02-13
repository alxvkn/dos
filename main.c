#include <stdint.h>

#include "printc.h"
#include "prints.h"

__asm__ (
        "call dosmain\n"
        "mov $0x4c, %ah\n"
        "int $0x21\n"
        );

const char* message = "hello msdos!\n";
const uint16_t message_length = 12;

void dosmain() {
    prints("hi dos\n");
    for (uint16_t i = 0; i < message_length; i++)
        printc(message[i]);

    return;
}
