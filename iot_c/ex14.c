#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINESIZE 80
#define LINECOUNT 100

int main(){
    char filename[100];
    char lines[LINECOUNT][LINESIZE];
    int lc = 0;
    int i;
    FILE *my_file;

    //asking the filename
    printf("Enter filename to open file:");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = '\0';


    //opening the file for reading
    my_file = fopen(filename, "r");
    if(my_file == NULL){
        fprintf(stderr, "Couldn't open %s.\n", filename);
        return 0;
    }else{

        printf("Reading from %s...\n", filename);

        while(lc < LINECOUNT && !feof(my_file)){
            if(fgets(lines[lc], LINESIZE, my_file) != NULL) {
                lc++;
            }   
        }

        printf("Read %d lines from %s\n", lc, filename);
        fclose(my_file);
    }

    for(i = 0; i < lc; i++) {
        printf("Line %d: %s \n", i, lines[i]);


        for(int j = 0; lines[i][j] !='\0'; j++){
            lines[i][j] = toupper(lines[i][j]);
        }
        
        printf("Uppercase %d: %s\n", i, lines[i]);

    }   


    //writing to the uppercase versions back to the same file because thats how I understood the assignment?
    my_file = fopen(filename, "w");
    if(my_file == NULL){
        fprintf(stderr, "Couldn't open %s.\n", filename);
        return 0;
    }else{

        printf("\nWriting to %s...\n", filename);

        for(i = 0; i < lc; i++) {
            fputs(lines[i], my_file);
            printf("Line %d: %s \n", i, lines[i]);
        }

        printf("\nWrote %d lines to %s\n", lc, filename);
        fclose(my_file);
    }
    
    return 0;
}