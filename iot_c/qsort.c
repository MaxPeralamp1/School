#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 32

typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
} student;

typedef enum { byGroup, byLastName, byFirstName } sort_order;

void get_names(const char*name, char *first, char *last){
    const char *gap = strchr(name, ' ');
    if(gap){
        size_t firstname_len = gap - name;
        strncpy(first, name, firstname_len);
        first[firstname_len] = '\0';

        strcpy(last, gap + 1);
    }else{
        strcpy(first, name);
        last[0] = '\0';
    }


}

int compare_by_group(const void *a, const void *b){
    return ((student *)a)->group - ((student *)b)->group;
}

int compare_by_lastname(const void *a, const void *b){
    char firstA[MAX_LEN], lastA[MAX_LEN];
    char firstB[MAX_LEN], lastB[MAX_LEN];

    get_names(((student *)a)->name, firstA, lastA);
    get_names(((student *)b)->name, firstB, lastB);

    int result = strcmp(lastA, lastB);
    if (result == 0) { 
        return strcmp(firstA, firstB);
    }
    return result;
}

int compare_by_first_name(const void *a, const void *b){
    char firstA[MAX_LEN], lastA[MAX_LEN];
    char firstB[MAX_LEN], lastB[MAX_LEN];

    get_names(((student *)a)->name, firstA, lastA);
    get_names(((student *)b)->name, firstB, lastB);

    int result = strcmp(firstA, firstB);
    if(result == 0){
        return strcmp(lastA, lastB);
    }
    return result;
}

void sort_students(student *students, int count, sort_order sb){
    if (count <= 0) {
        count = 0;
        while (students[count].id != 0) {
            count++;
        }
    }

    int(*fptr)(const void *, const void *);

    switch(sb){
        case byGroup:
            fptr = compare_by_group;
            break;
        case byFirstName:
            fptr = compare_by_first_name;
            break;
        case byLastName:
            fptr = compare_by_lastname;
            break;
        default:
            return;
    }
    qsort(students, count, sizeof(student), fptr);
}



    int main() {
        student students[] = {
            {"Alice Smith", 2, 101},
            {"Bob Johnson", 1, 102},
            {"Charlie Brown", 3, 103},
            {"David Adams", 2, 104},
            {"Eve Carter", 1, 105},
            {"", 0, 0}
        };
    
        printf("Before sorting:\n");
        for (int i = 0; students[i].id != 0; i++) {
            printf("%s (Group %d, ID %d)\n", students[i].name, students[i].group, students[i].id);
        }
    
        sort_students(students, 0, byLastName);
    
        printf("\nAfter sorting by last name:\n");
        for (int i = 0; students[i].id != 0; i++) {
            printf("%s (Group %d, ID %d)\n", students[i].name, students[i].group, students[i].id);
        }
    
        return 0;
    }
