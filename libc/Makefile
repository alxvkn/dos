ROOT_DIR = ..
include $(ROOT_DIR)/config.mk

LIB = libc.a

$(LIB): puts.o putchar.o _dos_write.o string.o
	ar rcs $@ $^

clean:
	$(RM) *.o $(LIB)

.PHONY: clean all
