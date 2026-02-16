#include <stdbool.h>

#include "_dos_write.h"

ssize_t _dos_write(const char* string, size_t len) {
    bool failed;
    size_t written;

    __asm__ volatile (
            "int $0x21\n"
            : "=a"(written)
            : "a"(0x4000), // function 40h "WRITE"
              "b"(1), // 1 for stdout
              "d"(string),
              "c"(len) // bytes to write
            : "cc", "memory"
        );

    return failed ? -1 : (ssize_t)written;
}
