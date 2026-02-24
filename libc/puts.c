#include "puts.h"
#include "string.h"

#include "_platform_write.h"

int puts(const char* string) {
    unsigned len = strlen(string);

    if (_platform_write(string, len) == -1) {
        return -1;
    }

    if (_platform_write("\r\n", 2) == -1) {
        return -1;
    }

    return 0;
}
