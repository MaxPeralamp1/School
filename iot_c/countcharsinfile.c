#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


char *my_gets(char *line, int size, FILE *stream){
    if (fgets(line, size, stream) != NULL) {
        return line; 
    }
    return NULL;  
}
int count_chars(const char *characters, FILE *stream){
    char line[100];
    int count = 0;

    while(my_gets( line, sizeof(line), stream) != 0){
        for (int i = 0; line[i] != '\0'; i++) {
            for (int j = 0; characters[j] != '\0'; j++) {
                if (line[i] == characters[j]) {
                    count++; 
                }
            }
        }
    }
    return count;

}

int main(){
    FILE *myfile;
    myfile = fopen("testtext.text", "r");
    char characters[] = {"ab"};
    int amount = count_chars(characters, myfile);
    printf("amount of characters %d", amount);

     
}