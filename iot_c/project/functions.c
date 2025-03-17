#include "functions.h"


//loads the file and populates the array with the data fourn in the fie
int loadReservations(const char *filename, Seats seats[], int *count){
    FILE *file = fopen(filename, "r");

    if(file == NULL){
        perror("erro opening file");
        return 1;
    }

    *count = 0;

    while(fscanf(file, " %49[^,], %49[^,], %d, %c\n", seats[*count].first_name, seats[*count].last_name, &seats[*count].row, &seats[*count].seat)==4){
        (*count)++;
        if (*count >= MAX_SEATS) break;
    }

    fclose(file);
    return 0;
}

//saves the reservatios in the csv file
int saveReservation(const char *filename, const Seats *seats){
    FILE *file = fopen(filename, "a");

    if(file == NULL){
        perror("erro opening file");
        return 1;
    }

    fprintf(file, "%s, %s, %d, %c\n", 
        seats->first_name,
        seats->last_name,
        seats->row,
        seats->seat);
    
    fclose(file);
    return 0;
}

//prompts user for row and validates input
int getValidRow(){
    char input[MAX_INPUT_LEN];
    int row;
    while (1) {
        printf("Enter a row number (1-26): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &row) == 1) {
                if (row >= 1 && row <= 26) {
                    return row;
                } else {
                    printf("Invalid row! Please enter a number between 1 and 26.\n");
                }
            } else {
                printf("Invalid input! Please enter a valid number.\n");
            }
        }
        //clear the bugger in case of shit inp
        while (getchar() != '\n'); 
    }
}

//prompts user for seat and validates input
char getValidSeat(){
    char input[MAX_INPUT_LEN];
    while (1) {
        printf("Enter a seat letter (A-F): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Remove the newline character
            input[strcspn(input, "\n")] = '\0';

            // Convert the input to uppercase to handle both lowercase and uppercase inputs
            char seat = toupper(input[0]);

            // Validate input
            if (strlen(input) != 1 || seat < 'A' || seat > 'F') {
                printf("Invalid input! Please enter a single letter between A and F.\n");
            } else {
                return seat;
            }
        }
        // Clear the buffer in case of invalid inp
        while (getchar() != '\n');
    }
}
void getValidName(char *name, int maxLength) {
    while (1) {
        printf("Enter your name:\n");
        if (fgets(name, maxLength, stdin) != NULL) {
            // Remove newline character if present
            name[strcspn(name, "\n")] = '\0';

            // Ensure that the name is not empty
            if (strlen(name) == 0) {
                printf("Invalid input! Name cannot be empty.\n");
                continue;
            }

            int valid = 1;
            // Validate that the name contains only letters and spaces
            for (int i = 0; name[i] != '\0'; i++) {
                if (!isalpha(name[i]) && name[i] != ' ') {
                    valid = 0;
                    break;
                }
            }

            if (valid) {
                return;  // Valid name, exit the function
            } else {
                printf("Invalid input! Name should only contain letters and spaces.\n");
            }
        } else {
            printf("Input erro. Please try again.\n");
            while (getchar() != '\n');  // Clear input buffer in case of errors
        }
    }
}
//check if seat i taken
int isSeatAvailable(const Seats seats[], int count, int row, char seat){
    for(int i = 0; i < count; i++){
        if(seats[i].row == row && seats[i].seat == seat){
            //retun 0 if the seat is taken
            return 0;
        }
    }
    return 1;

}
//add a reservaton
int addReservation(Seats seats[], int *count, const char *filename){
    if (*count >= MAX_SEATS) {
        printf("The airplane is full yay no konkurssi happening\n");
        return 0;
    }

    Seats new_reservation;

    // Get user input for first and last name
    printf("Enter passenger details\n");
    getValidName(new_reservation.first_name, MAX_NAME_LEN);
    getValidName(new_reservation.last_name, MAX_NAME_LEN);

    // Get and validate row number
    new_reservation.row = getValidRow();

    // Get and validate seat letter
    new_reservation.seat = getValidSeat();

    // Check if the seat is available
    if (!isSeatAvailable(seats, *count, new_reservation.row, new_reservation.seat)) {
        printf("Error: Seat %d%c is already taken!\n", new_reservation.row, new_reservation.seat);
        return 0;
    }
    seats[*count] = new_reservation;
    (*count)++;

    // Save the new reservation to the file
    if (saveReservation(filename, &new_reservation) != 0) {
        printf("Error saving reservation to file!\n");
        return 0;
    }

    printf("Reservation for %s %s added successfully (Row %d Seat %c).\n",
           new_reservation.first_name, new_reservation.last_name,
           new_reservation.row, new_reservation.seat);

    return 1;  // Success

}
//remove reservation
int removeReservation(Seats seats[], int *count, const char *filename){
    int row = getValidRow();
    char seat = getValidSeat();

    int index = findReservation(seats, *count, row, seat);
    if (index == -1) {
        printf("No reservation found for row %d seat %c.\n", row, seat);
        return 0;
    }

    // Shift elements left to remove the reservation
    for (int i = index; i < *count - 1; i++) {
        seats[i] = seats[i + 1];
    }
    (*count)--;

    // Rewrite the entire file with updated data
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for updating");
        return 0;
    }

    for (int i = 0; i < *count; i++) {
        fprintf(file, "%s,%s,%d,%c\n",
                seats[i].first_name, seats[i].last_name,
                seats[i].row, seats[i].seat);
    }

    fclose(file);
    printf("Reservation fo row %d seat %c has been removed.\n", row, seat);
    return 1;

}

void printSeatMap(const Seats seats[], int count){
    {
        printf("\nAirplane Seat Map:\n");
        printf("   A B C   D E F\n");
        printf("  ----------------\n");
    
        for (int row = 1; row <= MAX_ROWS; row++) {
            printf("%2d ", row);  // Print row number, aligned to 2 digits
    
            for (char seat = 'A'; seat <= 'F'; seat++) {
                // Check if this seat is reserved
                if (isSeatAvailable(seats, count, row, seat)) {
                    printf("%c ", seat);  // Free seats as uppercase letters
                } else {
                    printf("x ");  // Reserved seats as lowercase 'x'
                }    
                // Print aisle gap after seat 'C'
                if (seat == 'C') printf("  ");
            }
    
            printf("\n");
        }
    
        printf("\n");
    }
}
//prints the passenger list
void printPassengerList(const Seats seats[], int count){
    if(count == 0){
        printf("No reservations found empty plane i guess(We are going bankrupt)");
    }
    for(int i = 0; i < count; i++){
        printf("%-20s %-20s %-5d %-5c\n", seats[i].last_name, seats[i].first_name, seats[i].row, seats[i].seat);
    }
}


//compare function for qsort
//compares by last name and if they match then by first
int compare(const void *a, const void *b){
    Seats *seatsA = (Seats *)a;
    Seats *seatsB = (Seats *)b;

    int lastNComparison = strcmp(seatsA->last_name, seatsB->last_name);
    if(lastNComparison != 0){
        return lastNComparison;
    }

    return strcmp(seatsA->first_name, seatsB->first_name);


}
void sortReservations(Seats seats[], int count){
    qsort(seats, count, sizeof(Seats), compare);
}

int findReservation(const Seats seats[], int count, int row, char seat){
    for (int i = 0; i < count; i++) {
        if (seats[i].row == row && seats[i].seat == seat) {
            return i; // Retur the index of the found reservation
        }
    }
    return -1; // Return -1 if not found
}



//pointers and printing according to example make me so mad holy f ehkä valitsin väärän alan lol