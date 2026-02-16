INCLUDES = -I$(ROOT_DIR)/libc/include

ASFLAGS = --32
CFLAGS = $(INCLUDES) -fno-pie -m16 -march=i386 -ffreestanding -fno-stack-protector -nostdinc
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti

LDFLAGS = -T$(ROOT_DIR)/com.ld -nostdlib

CC = clang
CXX = clang++
AR = llvm-ar
