#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

int main(){
    int input;
    srand(time(NULL));
    while(1){
        printf("Enter a number between 0-15: ");
        if(scanf("%d", &input) == 1) {

            if (input < 0){
                break;
            }

            if(input>= 0 && input<=15){
                int r = rand();
                printf("Int %d in hexadecimal = %x\n", r, r);
                r = r >> input;
                unsigned int mask = 0x3F;
                unsigned int result = r & mask;
                printf("Result after cleating bits: 0x%02X\n", result);
            }else{
                printf("Number too lsrge bruh\n");
            }
        } else {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
        }
    }
    return 0;
}