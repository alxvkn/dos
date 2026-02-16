#include "puts.h"
#include "string.h"

#include "_dos_write.h"

int puts(const char* string) {
    unsigned len = strlen(string);

    return _dos_write(string, len) == -1 ? -1 : 0;
}
