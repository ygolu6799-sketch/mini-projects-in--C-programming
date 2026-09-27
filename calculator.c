#include <stdio.h>
#include <stdlib.h>   // for exit()

// Function prototypes
void add();
void subtract();
void multiply();
void divide();
void modulus();

int main() {
    int choice;

    while (1) {
        // Menu
        printf("\n============================\n");
        printf("        CALCULATOR\n");
        printf("============================\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Exit\n");
        printf("============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: modulus(); break;
            case 6: 
                printf("Exiting program. Thank you!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function definitions
void add() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    printf("Result = %.2lf\n", a + b);
}

void subtract() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    printf("Result = %.2lf\n", a - b);
}

void multiply() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    printf("Result = %.2lf\n", a * b);
}

void divide() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    if (b != 0)
        printf("Result = %.2lf\n", a / b);
    else
        printf("Error: Division by zero not allowed!\n");
}

void modulus() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    if (b != 0)
        printf("Result = %d\n", a % b);
    else
        printf("Error: Division by zero not allowed!\n");
}