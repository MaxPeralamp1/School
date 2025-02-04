#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value){
    int input;
    printf("Enter a positive number: ");
    if(scanf("%d", &input) != 1){
        while (getchar() != '\n');
        return false;
    }

    if (input > 0){
        *value = input;
        return true;
    }else{
        return false;
    }
}

int main() {
    int incorret = 0;
    int number;
    while (incorret < 3){
        printf("Guess how much mone I have!\n");
        bool success = read_positive(&number);
        if (success){
            printf("You didn't get it right. I have %d euros.\n", number*2 + 20);
        }else{
            printf("Incorrect input.\n");
            incorret++;
        }
    }
    printf("I give up! See you later!");
    return 0;

}