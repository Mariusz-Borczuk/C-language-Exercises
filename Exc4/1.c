#include <stdio.h>
// ### Factorial

//**Goal:** Define a new function named `factorial()`, 
//which will calculate the factorial using recursive multiplication (5! = 5 x 4 x 3 x 2 x 1). 
//Note that according to convention, the factorial of 0 is equal to 1 (0! = 1).
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Enter the number to know its froctional: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);
    printf("Press any key to continue...\n");
    scanf("%d");
    return 0;
}