#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int print_numbers(const int *array, int count){
    for(int i=0; i<count; i++){
        printf("%8d\n ", array[i]);
    }

}

int main(){
    int count = 15;
    int array[count];
    srand(time(NULL));
    for(int i = 0; i < 14; i++){
        array[i] = rand() % 101;
    }
    print_numbers(array, count);
    return 0;
}