#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char filename[100];
    char line[100];
    int value = 0;
    int count= 0;
    int largest= INT_MAX;
    int smallest= INT_MAX;
    FILE *my_file;
    

    printf("Enter filename to open file:");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    my_file = fopen(filename, "r");

    if(my_file == NULL){
        fprintf(stderr, "Couldn't open %s.\n", filename);
        return 0;
    }else{
        printf("Reading numbers from %s...\n", filename);
        while(fgets(line, 100, my_file) != NULL) {
            if(sscanf(line, "%d", &value)==1){
                count++;
                printf("Read %d\n", value);
                if (value > largest){
                    largest = value;
                }else if (value < smallest){
                    smallest = value;
                }
            }else{
                printf("Invalid line");
            }
            

        }
        fclose(my_file);
        printf("Count of numbers was %d, largest num %d and smallest num %d", count, largest, smallest);
    }

    return 0;
}