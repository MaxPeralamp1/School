#include <stdio.h>
#include <string.h>

void replace(char *str) {
    int i;
    char target = 't';
    char replacement = '*';
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            str[i] = replacement;
        }
    }
}

int main() {
    char test1[] = "Two teas to thirtytwo";
    char test2[] = "this is a t-test";
    char test3[] = "where have all the flowers gone there's not a single one left here";

    replace(test1);
    replace(test2);
    replace(test3);

    printf("%s\n", test1);
    printf("%s\n", test2);
    printf("%s\n", test3);
    return 0;
}