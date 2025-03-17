#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdarg.h>


void set_debug_level(int debug_level);
int debug_printf(int debug_level, const char *fmt, ...);

#endif // DEBUG_H