# the -m16 generates 32-bit code and adds .code16gcc directive to assembly

ROOT_DIR = .
include config.mk

EXE := a.com

DOS_LIBC_DIR = libc

DOS_LIBC = $(DOS_LIBC_DIR)/libc.a

CRT0 = $(DOS_LIBC_DIR)/crt0.o

all: $(EXE) cpp$(EXE)

$(EXE): $(CRT0) main.o $(DOS_LIBC)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

cpp$(EXE): cppmain.o $(DOS_LIBC)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CRT0) $^ -o $@

FORCE:

$(DOS_LIBC): FORCE
	$(MAKE) -C $(DOS_LIBC_DIR)

run: $(EXE)
	dosbox $(EXE)

runcpp: cpp$(EXE)
	dosbox $^

clean:
	$(RM) *.o $(EXE) cpp$(EXE)
	$(MAKE) -C $(DOS_LIBC_DIR) clean

.PHONY: clean all FORCE
