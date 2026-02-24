#pragma once

#include <stdint.h>

#define NULL ((void*)0)

typedef uint32_t size_t;
typedef int32_t ptrdiff_t;

#define offsetof(type, member) ((size_t)&(((type*)0)->member))

typedef int32_t ssize_t; // actually not defined in standard, but useful
