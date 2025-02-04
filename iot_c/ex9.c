#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int find_first(const unsigned int *array, unsigned int what){
    int arrayindex = 0;
    while(array[arrayindex] != 0){
        if(array[arrayindex] == what){
            return arrayindex;
        }
        arrayindex++;
    }
    return -1;

}   

int main(){
    int array[20];
    unsigned int what;
    srand(time(NULL));
    for(int i = 0; i < 19; i++){
        array[i] = rand() % 20 + 1;
    }
    array[19] = 0;
     for(int i=0; i<20; i++){
        printf("%d\n ", array[i]);
    }
    while (1){
        printf("\nEnter a number to find: ");
        if(scanf("%d", &what) != 1){
        while (getchar() != '\n');
        printf("Invalid input. Please enter an integer.\n");
    }
        if (what != 0){
            int result = find_first(array, what);
            if(result != -1){
                printf("\nThe number %d was found at index %d\n", what, result);
            }else{
                printf("\nThe number %d was not found in the array.\n", what);
            }
        }else{
            printf("\nExiting the program...\n");
            return 0;
        }
    }
}