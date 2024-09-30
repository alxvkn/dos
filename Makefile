# the -m16 generates 32-bit code and adds .code16gcc directive to assembly
CFLAGS = -fno-pie -m16 -march=i386 -nostdlib -Wl,-Tcom.ld
CC = clang

EXE := a.com

$(EXE): main.c
	$(CC) $(CFLAGS) $^ -o $@

run: $(EXE)
	dosbox $(EXE)

main.s: main.c
	$(CC) $(CFLAGS) -S $^ -o $@

clean:
	$(RM) main.s $(EXE)
