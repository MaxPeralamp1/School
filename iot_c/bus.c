#include <stdio.h>

int main() {
    float bus_price, taxi_price, money;

    printf("Enter price of bus ticket: ");
    scanf("%f", &bus_price);

    printf("Enter price of taxi: ");
    scanf("%f", &taxi_price);

    printf("How much money you have: ");
    scanf("%f", &money);

    while (1) {
        if (money < bus_price && money < taxi_price) {
            printf("You need to walk. Bye\n");
            break;
        }

        int choice;
        printf("You have %.2f euros left.\n", money);
        printf("Do you want to take\n1) bus (%.2f euros)\n2) taxi (%.2f euros)\n", bus_price, taxi_price);
        printf("Enter your selection: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (money >= bus_price) {
                money -= bus_price;
                printf("You chose bus.\n");
                printf("You have %.2f euros left.\n", money);
            } else {
                printf("You don’t have enough money for bus.\n");
            }
        } else if (choice == 2) {
            if (money >= taxi_price) {
                money -= taxi_price;
                printf("You chose taxi.\n");
                printf("You have %.2f euros left.\n", money);
            } else {
                printf("You don’t have enough money for taxi.\n");
            }
        } else {
            printf("Invalid choice. Please select 1 or 2.\n");
        }
    }

    return 0;
}
