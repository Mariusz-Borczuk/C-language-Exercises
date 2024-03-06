#include <stdio.h>
#include <stdlib.h>

// If we list all the natural numbers below 10 that are multiples of 3 or 5,  we get 3, 5, 6, and 9. 
//The sum of these multiples is 23. Modify the solution 
// to return the sum of all the multiples of 3 or 5 below the given number. 
// Additionally, if the number is negative, return 0. 
// Note: If the number is a multiple of both 3 and 5, count it only once.
int main() {
    int number;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("The number is negative. Returning 0.\n");
        return 0;
    }

    for (int i = 1; i < number; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    printf("Suma wielokrotnosci 3 lub 5 ponizej %d wynosi: %d\n", number, sum);

    return 0;
}
