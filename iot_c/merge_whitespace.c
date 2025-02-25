#include <stdio.h>
#include <ctype.h>

void merge_whitespace(char *str) {
    if (!str || !*str) return;

    char *src = str, *dest = str;
    int space_flag = 0; 
    int leading_space = 1; 

    while (*src) {
        if (isspace((unsigned char)*src)) {
            if (!space_flag) { 
                *dest++ = ' '; 
                space_flag = 1;
            }
        } else {
            *dest++ = *src; 
            space_flag = 0;
            leading_space = 0;
        }
        src++;
    }

    // Remove trailing space if present
    if (dest > str && *(dest - 1) == ' ') {
        dest--;
    }

    *dest = '\0';
}

int main() {
    char test1[] = "  Hello\tworld!\nThis is  a  test.   ";
    char test2[] = "\t\t  ";
    char test3[] = "NoExtraSpaces";
    char test4[] = "   \n  Leading and trailing spaces. \t ";

    merge_whitespace(test1);
    merge_whitespace(test2);
    merge_whitespace(test3);
    merge_whitespace(test4);

    printf("Test 1: \"%s\"\n", test1);
    printf("Test 2: \"%s\"\n", test2);
    printf("Test 3: \"%s\"\n", test3);
    printf("Test 4: \"%s\"\n", test4);

    return 0;
}