#include "debug.h"

static int current_debug_level = 0;

void set_debug_level(int debug_level){
    current_debug_level = debug_level;
}

int debug_printf(int debug_level, const char *fmt, ...){
    if(debug_level > current_debug_level){
        return 0;
    }

    fprintf(stderr, "[DBG%d] ", debug_level);

    va_list args;

    va_start(args, fmt);
    int result = vfprintf(stderr, fmt, args);
    va_end(args);

    return result;
}