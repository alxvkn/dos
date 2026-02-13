#include "printc.h"

void printc(char c) {
    __asm__ volatile (
        "mov $0x02, %%ah\n"
        "mov %0, %%dl\n"
        "int $0x21\n"
        :
        : "r"(c)
        : "ah", "dl"
        );
}
