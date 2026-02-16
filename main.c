#include <stddef.h>
#include <stdio.h>
#include <string.h>

const char* message = "hello msdos!";

int main(int argc, char** argv) {
    puts("hi dos");


    for (unsigned i = 0; i < argc; i++)
        puts(argv[i]);

    const size_t message_length = strlen(message);

    for (unsigned i = 0; i < message_length; i++)
        putchar(message[i]);

    return 0;
}
