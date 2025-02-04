#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace_char(char *str, const char *repl){
    int replacedChar = 0;

    if(strlen(repl) != 2){
        return 0;
    }

    for (int i= 0; i < strlen(str); i++){
        if(str[i] == repl[0]){
            str[i] = repl[1];
            replacedChar++;
        }
    }
    
    return replacedChar;

}

int main(){
    char str[100];
    char repl[3];
    
    printf("Enter a string to replace:");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the 2 characters to replace(1st letter is the one that gets replaced 2nd replaces):");
    scanf("%2s", repl);
    
    int replacedChar = replace_char(str, repl);
    
    if(replacedChar > 0){
        printf("%s\n", str);
        printf("Number of replaced characters: %d\n", replacedChar);
    }else{
        printf("String was not modified");
    }
    return 0;
    
}