#include <stdio.h>

int main() {
    float taxRate, incomeLimit, overTax;
    float salaries[12];
    float taxes[12];

    printf("Enter tax rate: ");
    scanf("%f", &taxRate);

    printf("Enter income limit: ");
    scanf("%f", &incomeLimit);

    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &overTax);

    for (int i = 0; i < 12; i++) { 
        printf("Enter salary for month %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    
    for (int i = 0; i < 12; i++) {
        float salary = salaries[i];
        float tax = 0.0;

        if (salary <= incomeLimit) {
            tax = salary * (taxRate / 100.0);
        } else {
            tax = incomeLimit * (taxRate / 100.0);
            tax += (salary - incomeLimit) * (overTax / 100.0);
        }

        taxes[i] = tax;
    }

    
    printf("month     income        tax\n");
    for (int i = 0; i < 12; i++) {
        printf("%3d %10.2f %10.2f\n", i + 1, salaries[i], taxes[i]);
    }

    return 0;
}