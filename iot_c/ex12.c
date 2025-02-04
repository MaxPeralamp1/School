#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count_words(const char *str, const char *word){
    int count = 0;
    char *index = str;
    
    if(strlen(word) == 0){
        return 0;
    }

    while((index = strstr(index, word)) != NULL){
        count++;
        index += strlen(word);
    }

    return count;
    
    
}

int main(){
    char str[100];
    char word[100];

    while(1){
        printf("Entere a string:");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
        printf("Enter the word to count:");
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0';

        if(strcmp(word, "stop") == 0){
            printf("Input was stop exiting program...\n");
            return 0;
        }

        int replacedWords = count_words(str, word);

        if(replacedWords > 0){
            printf("%s\n", str);
            printf("Occuranses of word: %d\n", replacedWords);
        }else{
            printf("String was not modidied\n");
        }
    }
}