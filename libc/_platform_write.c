#include <stdbool.h>

#include "_platform_write.h"

static ssize_t _dos_write(const char* string, size_t len) {
    bool failed;
    size_t written;

    __asm__ volatile (
            "int $0x21\n"
            : "=a"(written), "=@ccc"(failed)
            : "a"(0x4000), // function 40h "WRITE"
              "b"(1), // 1 for stdout
              "d"(string),
              "c"(len) // bytes to write
            : "cc", "memory"
        );

    return failed ? -1 : (ssize_t)written;
}

static ssize_t _bios_write(const char* string, size_t len) {
    bool failed;
    size_t written;

    for (size_t i = 0; i < len; i++) {
        char c = string[i];
        __asm__ volatile (
                "int $0x10\n"
                :
                : "a"(0x0e << 8 | c)
                : "cx", "dx");
    }

    return failed ? -1 : (ssize_t)written;
}

ssize_t _platform_write(const char* string, size_t len) {
    return _bios_write(string, len);
}
