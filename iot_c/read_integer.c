#include <stdio.h>


int read_integer(void) {
    int selection;
    while (1) {
        printf("Enter positive numbers or negative to stop: ");
        if (scanf("%d", &selection) == 1) {
            return selection;
        } else {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
        }
    }

}
int main() {
    int num;
    int sum = 0;
    int count = 0;
    double average;

    while(1){
        num = read_integer();
        if(num < 0){
            break;
        } else{
            count++;
            sum += num;
        }
    }
    average = (double)sum / count;
    printf("You entered %d positive numbers. The average is:  %f", count, average);
    return 0;
}

