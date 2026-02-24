#include <stdint.h>
#include "stddef.h"
static char cmd_buf[128];
static char* argv_list[16];

extern int main(int argc, char** argv);

static void _dos_c_startup() {
    uint8_t* psp = (uint8_t*)0;
    uint8_t cmdlen = psp[0x80];

    for (uint8_t i = 0; i < cmdlen; i++) {
        char c = psp[0x81 + i];
        if (c == '\r') c = '\0';
        cmd_buf[i] = c;
    }

    cmd_buf[cmdlen] = '\0';

    int argc = 0;
    argv_list[argc++] = "program";

    char* p = cmd_buf;
    while (*p && argc < 15) {
        while (*p == ' ') p++;
        if (*p == '\0') break;

        argv_list[argc++] = p;

        while (*p && *p != ' ') p++;
        if (*p == ' ') *p++ = '\0';
    }

    argv_list[argc] = NULL;

    int exit_code = main(argc, argv_list);

    asm volatile("" : : "a"(exit_code));
}

void _c_startup() {
    return _dos_c_startup();
}
