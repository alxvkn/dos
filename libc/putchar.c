#include "putchar.h"

#include "_platform_write.h"

int putchar(int c) {
    unsigned char ch = (unsigned char)c;

    return _platform_write((const char*)&ch, 1) == 1 ? c : -1;
}
