#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    while(1){
        char str[100];
        printf("Enter a string:");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
        printf("String length: %d\n", strlen(str));
        if(strcmp(str, "stop") == 0){
            printf("Input was stop exiting program...\n");
            return 0;
        }
    }
}