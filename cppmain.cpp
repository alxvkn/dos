#include <stdint.h>

#include "printc.h"
#include "prints.h"

__asm__ (
        "call dosmain\n"
        "mov $0x4c, %ah\n"
        "int $0x21\n"
        );

const char* message = "hello msdos!\n";
const uint16_t message_length = 12;

class Repeater {
    public:
    Repeater(const char* string, int times) : _string(string), _times(times) {
        prints("constructor\n");
    }

    ~Repeater() {
        prints("destructor\n");
    }

    void print() {
        for (uint16_t i = 0; i < _times; i++) {
            for (uint16_t j = 0; _string[j] != '\0'; j++)
                printc(_string[j]);
            printc('\n');
        }
    }

    private:
    const char* const _string;
    const int _times;
};

extern "C" void dosmain() {
    prints("hi dos\n");

    Repeater r = Repeater("hi", 5);
    r.print();

    return;
}
