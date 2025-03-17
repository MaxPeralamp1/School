#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 256
#define MAX_FILE_LENGTH 100

int main(){
    char filename[MAX_FILE_LENGTH];
    char line[LINE_LENGTH];
    int value = 0;
    int count= 0;
    FILE *my_file;
    

    printf("Enter filename to open file:");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    my_file = fopen(filename, "r");

    if(my_file == NULL){
        fprintf(stderr, "Couldn't open %s.\n", filename);
        return 0;
    }else{
        printf("Reading from %s...\n", filename);
        while(fgets(line, sizeof(line), my_file) != NULL) {

            if (line[0] == '$' && strchr(line, '*')) {
                char *ast = strchr(line, '*');
                unsigned char checksum = 0;

                for (char *p = line + 1; p< ast; p++){
                    checksum ^= *p;
                }

                unsigned int fChecksum;
                if(sscanf(ast + 1, "%2x", &fChecksum)!=1){
                    printf("[FAIL] %s", line);
                    continue;
                }

                if(checksum == fChecksum){
                    printf("[OK] %s", line);
                }else{
                    printf("[FAIL] %s", line);
                }


            }
        }
        
    }

    fclose(my_file);
    return 0;
}