ROOT_DIR = ..
include $(ROOT_DIR)/config.mk

LIB = libc.a

STARTUP = crt0.o

all: $(LIB) $(STARTUP)

$(LIB): puts.o putchar.o _dos_write.o string.o c_startup.o
	ar rcs $@ $^

clean:
	$(RM) *.o $(LIB)

.PHONY: clean all
