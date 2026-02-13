#include "prints.h"

void _prints(const char* string) {
    __asm__ volatile (
            "mov $0x09, %%ah\n"
            "int $0x21\n"
            :
            : "d"(string)
            : "ah"
        );
}
