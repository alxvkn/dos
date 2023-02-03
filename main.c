#include <stdint.h>

__asm__ (
        "call dosmain\n"
        "mov $0x4c, %ah\n"
        "int $0x21\n"
        );

static void printc(char c) {
    __asm__ volatile (
        "mov $0x02, %%ah\n"
        "mov %0, %%dl\n"
        "int $0x21\n"
        :
        : "r"(c)
        : "ah", "dl"
        );
}

static void prints(const char* string) {
    __asm__ volatile (
            "mov $0x09, %%ah\n"
            "int $0x21\n"
            :
            : "d"(string)
            : "ah"
        );
}
#define prints(string) do { prints(string "$"); } while (0)

const char* message = "hello msdos!\n";
const uint16_t message_length = 12;

void dosmain() {
    prints("hi dos\n");
    for (uint16_t i = 0; i < message_length; i++)
        printc(message[i]);

    return;
}
