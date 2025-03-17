#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char my_getchar(void){
    static const char *input = "He11o! W@orld123";  // Example input
    static int index = 0;

    if (input[index] == '\0') {
        return 0;  // End of input
    }
    return input[index++];
}

int filter_alpha(char *word, size_t size, char (*get_char)(void)){
    size_t i = 0;
    int count = 0;
    char c;

    while ((c = my_getchar()) != 0 && c != '\n') {  
        count++;
        if (i < size -1 && isalpha((unsigned char)c)) {  
            word[i++] = c;
            
        }
    }
    word[i] = '\0';
    return count;
}


int main() {
    char filtered[20];  // Buffer size including null terminator
    
    int chars_read = filter_alpha(filtered, sizeof(filtered), my_getchar);
    
    printf("Filtered String: %s\n", filtered);  // Expected Output: "HllWrld"
    printf("Total Characters Read: %d\n", chars_read);  // Expected Output: 12 (excluding '\0')

    return 0;
}