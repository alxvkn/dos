# the -m16 generates 32-bit code and adds .code16gcc directive to assembly
CFLAGS = -fno-pie -m16 -march=i386 -ffreestanding
CXXFLAGS = $(CFLAGS) -fno-stack-protector -fno-exceptions -fno-rtti

LDFLAGS = -Tcom.ld -nostdlib

CC = clang
CXX = clang++

EXE := a.com

$(EXE): main.o printc.o prints.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

cpp$(EXE): cppmain.o printc.o prints.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

run: $(EXE)
	dosbox $(EXE)

runcpp: cpp$(EXE)
	dosbox $^

clean:
	$(RM) *.o $(EXE) cpp$(EXE)
