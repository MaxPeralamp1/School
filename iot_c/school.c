#include <stdio.h>

int main(){
    int students, grade, studentNumber;
    printf("How many students: ");
    scanf("%d", &students);
    int grades[students];
    for (int i = 0; i < students; i++) {
        grades[i] = -1;
    }

    while(1){
        printf("Enter student number (1 – %d) or 0 to stop: ", students);
        scanf("%d", &studentNumber);

        if(studentNumber >= 1 && studentNumber <= students){
            printf("Enter grade (0-5) or -1 to stop: ");
            scanf("%d", &grade);

            if (grade == -1) {

            } else if (grade >= 0 && grade <= 5) {
                grades[studentNumber - 1] = grade;
                
            } else {
                printf("Invalid grade! Please enter a grade between 0 and 5 or -1 to cancel: \n");
            }

        }else if(studentNumber < 0 || studentNumber >= students){
    
            printf("Invalid student number. Please try again.\n");
        

        }else{
            printf("Invalid student number!");
            break;

        }
    
    }

    printf("\nStudent\tGrade\n");
    for (int i = 0; i < students; i++) {
        if (grades[i] == -1) {
            printf("%d\tN/A\n", i + 1);
        } else {
            printf("%d\t%d\n", i + 1, grades[i]);
        }
    }

    return 0;
}