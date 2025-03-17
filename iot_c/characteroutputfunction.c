#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


void print_char(char ch){
    putchar(ch);
}


int print_string(const char *word, void (*op)(char)){
    int i = 0;
    while(word[i] != '\0'){
        op(word[i]);
        i++;
    }

    return i;


}


int main(){
    char string[100];

    void (*fptr)(char);

    fptr = &print_char;

    while(1){
        printf("Enter a word: ");
        if(fgets(string, sizeof(string), stdin)== NULL){
            printf("Error reading input\n");
            continue;
        }

        string[strcspn(string, "\n")] = '\0';

        if(strlen(string) >=99){
            printf("Input too long.");
            int ch;
            while((ch = getchar())!= '\n' && ch != EOF);
            continue;
        }

        if(strcmp(string, "end") == 0){
            break;
        }

        print_string(string, fptr);

    }

    return 0;
}