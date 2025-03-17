#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

bool generate_password(char *pointer, int size, const char *word){
    int wordlength = strlen(word);
    int pswordlen = 2 * wordlength + 1;

    if(size <= pswordlen){
        return false;
    }

    pointer[0] = (char)(32 + (rand() % (126 - 32 + 1)));

    for (int i = 0; i < wordlength; i++){
        pointer[i  * 2 + 1] = word[i];
        pointer[i * 2 + 2] = (char)(32 + (rand() % (126 - 32 + 1)));
    }

    pointer[pswordlen - 1] = (char)(32 + (rand() % (126 - 32 + 1)));
    pointer[pswordlen] = '\0';
    
    return true;
}


int main(){
    char input[32];
    char password[100];

    srand((unsigned int)time(NULL));
    
    printf("Enter a password or end to stop\n");
    while(1){
        printf("Enter a word: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) >= 31) {
            printf("Your input is too long\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        if(strcmp(input, "end") == 0){
            break;
        }

        if (generate_password(password, sizeof(password), input)){
            printf("generated password: %s \n", password);
        }else{
            printf("Generated password could not fit in the buffer.");
        }
    }

    return 0;


}