#pragma once

#define NULL ((void*)0)

typedef unsigned short size_t;
typedef signed short ptrdiff_t;

#define offsetof(type, member) ((size_t)&(((type*)0)->member))

typedef signed short ssize_t; // actually not defined in standard, but useful
