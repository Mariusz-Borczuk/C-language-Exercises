#include <stdio.h>
#include <stdlib.h>

// Calculate factorial for each number in the array int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }.
// This should be a function that takes an array as input and calculates the factorial for each number in the array.
int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int result = 1;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= array[i]; j++) {
            result *= j;
        }
        
        printf("Factorial of %d is %d\n", array[i], result);
        result = 1;
    }
    
    return 0;
}