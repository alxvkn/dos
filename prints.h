#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void _prints(const char* string);

#define prints(string) do { _prints(string "$"); } while (0)

#ifdef __cplusplus
}
#endif
