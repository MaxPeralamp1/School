#include <string.h>
#include <ctype.h>
#include <stdbool.h>


void sort3(int *pa[3]){

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (*pa[j] > *pa[j + 1]) {
                int *temp = pa[j];
                pa[j] = pa[j + 1];
                pa[j + 1] = temp;
            }
        }
    }

}


#define TEST_SIZE 12

int main(int arcg, char **argv)
{
    const int v[TEST_SIZE] = { 1, 2, 3, 7, 4, 9, 12, 4, -1, 67, 67, 34 };
    int a[TEST_SIZE];
    int *ta[3];

    for (int i = 0; i < TEST_SIZE; i++) a[i] = v[i];

    for (int k = 0; k < TEST_SIZE; k += 3) {
        for (int i = 0; i < 3; ++i) {
            ta[i] = &a[i+k];
        }
        sort3(ta);

        printf("%d, %d, %d\n", *ta[0], *ta[1], *ta[2]);
    }

    for (int i = 0; i < TEST_SIZE; ++i) {
        if(a[i] != v[i]) printf("Data corrupted\n");
    }

    return 0;

}