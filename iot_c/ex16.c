#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    int number;
    struct node *next;
} nnode;


void add_node(nnode **head, int num) {
    nnode *new_node = (nnode *)malloc(sizeof(nnode));
    if (!new_node) {
        fprintf(stderr, "Joo ei vittu toimi\n");
        exit(1);
    }
    new_node->number = num;
    new_node->next = *head; 
    *head = new_node;
}


void free_list(nnode *head) {
    nnode *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    nnode *head = NULL;
    char input[100];

    printf("Enter numbers (or type 'end' to stop):\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 

        if (strcmp(input, "end") == 0) {
            break;  
        }

      
        int valid = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i]) && !(i == 0 && input[i] == '-')) { 
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Invalid input! Please enter a valid number or 'end'.\n");
            continue;
        }

        int num = atoi(input);
        add_node(&head, num);
    }


    printf("\nEntered numbers:\n");
    nnode *current = head;
    while (current) {
        printf("%d\n", current->number);
        current = current->next;
    }


    free_list(head);
    return 0;
}
    //mä sekoon mä sekoon mä sekoon mä sekoon