#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#include "debug.h"

int main(){
int debug_level;
    printf("Enter a debug lever(0-4)");
    if (scanf("%d", &debug_level) != 1 || debug_level < 0 || debug_level > 4) {
        printf("Invalid input. Please enter a number between 0 and 4.\n");
        return 1;
    }

    set_debug_level(debug_level);

    srand(time(NULL));

    for (int i = 1; i<= 5; i++){
        int random_debug_level = rand()%5;
        debug_printf(random_debug_level, "MEssage %d debug level %d\n", i, random_debug_level);
    }

    return 0;
}