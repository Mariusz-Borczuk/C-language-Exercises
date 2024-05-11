#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10];
    int *ptr = array;

    // Array initialization
    for (int i = 0; i < 10; i++) {
        array[i] = (i+i+i)*69;
    }

    // Displaying the contents of the array using a pointer
    for (int i = 0; i < 10; i++) {
        printf("Value of element %d: %d\n", i, *ptr);
        ptr++;
    }

    return 0;
}