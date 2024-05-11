#include <stdio.h>
#include <stdlib.h>

// Function for addition
int addition(int a, int b) {
    return a + b;
}

// Function for multiplication
int multiplication(int a, int b) {
    return a * b;
}

// Function for subtraction
int subtraction(int a, int b) {
    return a - b;
}

int main() {
    int (*pointer)(int, int); // Declare a function pointer
    int a, b, result;
    char operation;

    printf("Welcome to Function pointers!\n");
    printf("Enter the first number: ");
    scanf("%d", &a);

    printf("Enter the second number: ");
    scanf("%d", &b);

    printf("Enter the operation (a - addition, m - multiplication, s - subtraction): ");
    scanf(" %c", &operation);

    switch (operation) {
        case 'a':
            pointer = addition; // Assign the function pointer to the addition function
            break;
        case 'm':
            pointer = multiplication; // Assign the function pointer to the multiplication function
            break;
        case 's':
            pointer = subtraction; // Assign the function pointer to the subtraction function
            break;
        default:
            printf("Unknown operation!\n");
            return 1;
    }

    result = pointer(a, b); // Call the function through the function pointer
    printf("Result: %d\n", result);

    // wait for key press before exiting
    scanf("Press any key to exit...");

    return 0;
}