#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d6(){
    int x = 7;
        while (x > 6) 
            x = 1 + rand() / ((RAND_MAX + 1u) / 6);
        printf("You rolled %d\n", x);
        return 0;
        
}

int d10(){
    int x = 11;
        while (x > 10) 
            x = 1 + rand() / ((RAND_MAX + 1u) / 10);
        printf("You rolled %d\n", x);
        return 0;
}

int main(){
    srand(time(NULL));
    int input;
    printf("It's time to play the game, it's time to play the gaaaaame!. Do you wanna:\n");
    while(1){
        printf("Roll D6 (Input 1)\nRoll D10 (Input 2)\nOr quit the game(Input 3)\n");
        if (scanf("%d", &input) == 1) {  
            if(input == 1){
                d6();
            } else if(input == 2){
                d10();
            } else if(input == 3){
                printf("Quitting the fuckass game");
                return 0;
            } else{
                printf("Invalid fucking option, can you not read?");
            }
        } else {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
        }
    }
}