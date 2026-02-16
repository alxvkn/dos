#include <stdio.h>

__asm__ (
        "call dosmain\n"
        "mov $0x4c, %ah\n"
        "int $0x21\n"
        );

const char* message = "hello msdos!\n";
const unsigned message_length = 12;

class Repeater {
    public:
    Repeater(const char* string, int times) : _string(string), _times(times) {
        puts("constructor\n");
    }

    ~Repeater() {
        puts("destructor\n");
    }

    void print() {
        for (unsigned i = 0; i < _times; i++) {
            for (unsigned j = 0; _string[j] != '\0'; j++)
                putchar(_string[j]);
            putchar('\n');
        }
    }

    private:
    const char* const _string;
    const int _times;
};

extern "C" void dosmain() {
    puts("hi dos\n");

    Repeater r = Repeater("hi", 5);
    r.print();

    return;
}
