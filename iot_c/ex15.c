#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct menu_item_ { 
    char name[50]; 
    double price; 
} menu_item;


int main(){
    char filename[100];
    char line[100];
    FILE *my_file;
    menu_item arr[40];
    

    printf("Enter filename to open file:");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    my_file = fopen(filename, "r");

    if(my_file == NULL){
        fprintf(stderr, "Couldn't open %s.\n", filename);
        return 0;
    }else{
        printf("Reading from %s...\n", filename);
        int i = 0;
        while(fgets(line, 100, my_file) != NULL && i < 40) {
            line[strcspn(line, "\n")] = 0;
            char *name = strtok(line, ";");
            char *price = strtok(NULL, ";");

            if (name && price) {
                while (*price == ' ') price++;
    
                strncpy(arr[i].name, name, sizeof(arr[i].name) - 1);
                arr[i].name[sizeof(arr[i].name) - 1] = '\0'; 
                arr[i].price = atof(price);  
                i++;
            }

            

        }
        fclose(my_file);


        printf("\n%-50s %8s\n", "Item", "Price (€)");
        printf("-------------------------------------------------- --------\n");
        for (int j = 0; j < i; j++) {
            printf("%-50s %8.2f\n", arr[j].name, arr[j].price);
        }
        
    }

    return 0;
}