#include "functions.h"

void displayMenu() {
    printf("\nAirplane Seat Reservation System\n");
    printf("1. Add Reservation\n");
    printf("2. Remove Reservation\n");
    printf("3. Show Seat Map\n");
    printf("4. Prit Passenger List\n");
    printf("5. Quit\n");
    printf("Select an option: ");
}

int main() {
    Seats seats[MAX_SEATS];
    int count = 0;
    const char *filename = "reservations.csv";

    // Load existing reservations
    if (loadReservations(filename, seats, &count) != 0) {
        printf("Starting with an empty plane.\n");
    }

    int choice;
    do {
        displayMenu();
        
        // Get user input for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        // Clear any remaining newline character from the buffer
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                addReservation(seats, &count, filename);
                break;

            case 2:
                removeReservation(seats, &count, filename);
                break;

            case 3:
                printSeatMap(seats, count);
                break;

            case 4:
                sortReservations(seats, count);
                printPassengerList(seats, count);
                break;

            case 5:
                printf("Exiting system. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Pleae select a number between 1 and 5.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}