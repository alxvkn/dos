#pragma once

void _prints(const char* string);

#define prints(string) do { _prints(string "$"); } while (0)
