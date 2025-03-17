#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


bool binary_reader(unsigned int *value) {
    char buffer[256];

    while (read_line(buffer, 256)) {
        char *ptr = buffer;

        
        while (isspace((unsigned char)*ptr)) {
            ptr++;
        }

        
        if (ptr[0] == '0' && ptr[1] == 'b') {
            ptr += 2; 
            *value = 0;
            bool valid = false;

            
            while (*ptr == '0' || *ptr == '1') {
                *value = (*value << 1) | (*ptr - '0');
                ptr++;
                valid = true;
            }

            if (valid) {
                return true;
            }
        }
    }

    return false; 
}

int digit_counter(unsigned int value) {
    int digits = 0;

    do {
        digits++;
        value >>= 4;
    } while (value > 0);

    return digits;
}
