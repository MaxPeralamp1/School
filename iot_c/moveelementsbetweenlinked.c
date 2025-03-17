#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 32

typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
    struct student_ *next;
} student;

int move(student **source, int group, student **target){
    if(*source == NULL){
        return 0;
    }

    int moved = 0;
    student *prev = NULL;
    student *current = *source;

    while (current != NULL) {
        if (current->group == group) {
        
            if (prev == NULL) {  
                *source = current->next;
            } else {
                prev->next = current->next;
            }

            student *nextNode = current->next;
            current->next = *target;
            *target = current;
            moved++;
            current = nextNode;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return moved;

}

int main(){



    return 0;
}