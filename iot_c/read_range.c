#include <stdio.h>

int read_range(int low, int high){
   int number;
    while (1) {
        printf("Enter a number between %d and %d: ", low, high);
        if (scanf("%d", &number) == 1) {
            if (number >= low && number <= high){
                return number;
            }else{
                printf("Number must be between %d and %d.\n", low, high);
            }
                
        } else {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
        }
    }

}

int main(){
    int roll;
    printf("Lets play!\n");
    for (int i = 1; i <= 3; i++){
        roll = read_range(1, 6);

        if (roll == 6){
            printf("I got a 6. It's a tie!\n");
        }else{
            printf("I got a %d. I win! \n", roll+1);
        }
    }
    printf("Better luck next time!\n");
    return 0;
}