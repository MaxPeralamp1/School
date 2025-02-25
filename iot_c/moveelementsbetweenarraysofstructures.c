#include <stdio.h>

#define MAX_LEN 32

typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
} student;

int move(student *source, int group, student *target, int size) {
    int moved_count = 0;
    int target_index = 0;

    
    while (target_index < size && target[target_index].id != 0) {
        target_index++;
    }
    
    if (target_index >= size - 1) {
        return 0;
    }

    int i = 0;
    while (source[i].id != 0) {
        if (source[i].group == group) {
            
            if (target_index >= size - 1) {
                break;
            }
            
            target[target_index] = source[i];
            target_index++;
            moved_count++;

            int j = i;
            while (source[j].id != 0) {
                source[j] = source[j + 1];
                j++;
            }
            
        } else {
            i++; 
        }
    }
    
  
    if (target_index < size) {
        target[target_index].id = 0;
    }
    
    return moved_count;
}

int main() {
    student source[] = {
        {"Ian McShane", 1, 2019001},
        {"John Woo", 3, 2019007},
        {"Nick Name", 3, 2019019},
        {"Molly Westwood", 2, 2019021},
        {"Peter Thornton", 2, 2019031},
        {"Sammy Davis", 3, 2019671},
        {"Will Smith", 1, 2019761},
        {"Patti Smith", 4, 2018492},
        {"Willy Wonka", 2, 2016290},
        {"Jack Daniels", 4, 2016892},
        {"Ernie West", 1, 2015192},
        {"Sean Bean", 2, 2016112},
        {"Eric Idle", 2, 2017822},
        {"Susan Sarandon", 5, 2016034},
        {"Nick Cave", 5, 2015002},
        {0} // End marker
    };

    student target[8] = {{0}}; // Target array with space for 7 students + end marker

    // Initial state
    printf("Initial array:\n");
    for (int i = 0; source[i].id != 0; i++) {
        printf("%-16s, %-2d, %-7d\n", source[i].name, source[i].group, source[i].id);
    }
    
    int moved = move(source, 1, target, 8);
    printf("Moved %d elements\n", moved);
    printf("Array after removals:\n");

    // Print source array after removal
    for (int i = 0; source[i].id != 0; i++) {
        printf("%-16s, %-2d, %-7d\n", source[i].name, source[i].group, source[i].id);
    }

    // Print target array
    printf("Target array:\n");
    for (int i = 0; target[i].id != 0; i++) {
        printf("%-16s, %-2d, %-7d\n", target[i].name, target[i].group, target[i].id);
    }

    return 0;
}
