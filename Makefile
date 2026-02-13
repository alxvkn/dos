# the -m16 generates 32-bit code and adds .code16gcc directive to assembly
CFLAGS = -fno-pie -m16 -march=i386 -nostdlib
LDFLAGS = -Tcom.ld
CC = clang

EXE := a.com

$(EXE): main.o printc.o prints.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

run: $(EXE)
	dosbox $(EXE)

clean:
	$(RM) *.o $(EXE)
