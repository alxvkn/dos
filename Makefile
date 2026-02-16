# the -m16 generates 32-bit code and adds .code16gcc directive to assembly

ROOT_DIR = .
include config.mk

EXE := a.com

DOS_LIBC_DIR = libc

DOS_LIBC = $(DOS_LIBC_DIR)/libc.a

all: $(EXE) cpp$(EXE)

$(EXE): main.o $(DOS_LIBC)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

cpp$(EXE): cppmain.o $(DOS_LIBC)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(DOS_LIBC):
	$(MAKE) -C $(DOS_LIBC_DIR)

run: $(EXE)
	dosbox $(EXE)

runcpp: cpp$(EXE)
	dosbox $^

clean:
	$(RM) *.o $(EXE) cpp$(EXE)
	$(MAKE) -C $(DOS_LIBC_DIR) clean

.PHONY: clean all
