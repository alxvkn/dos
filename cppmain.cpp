#include <stdio.h>

class Repeater {
    public:
    Repeater(const char* string, int times) : _string(string), _times(times) {
        puts("constructor");
    }

    ~Repeater() {
        puts("destructor");
    }

    void print() {
        for (unsigned i = 0; i < _times; i++) {
            puts(_string);
        }
    }

    private:
    const char* const _string;
    const int _times;
};

extern "C" int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        Repeater r = Repeater(argv[i], 3);
        r.print();
    }

    return 0;
}
