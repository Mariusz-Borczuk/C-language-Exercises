#include <stdio.h>
//- Define a function that takes a pointer to a variable of type **`float`** and 
//modifies its value (e.g. doubles it).
//- In the **`main`** function, create a variable of type **`float`**, pass a pointer 
//to that variable to the function, and then print the new value of the variable.

void modifyFloat(float *ptr) {
    *ptr *= 2; // Podwajamy wartość zmiennej
}

int main() {
    float number = 5.0;
    printf("Wartość przed modyfikacją: %.2f\n", number);
    
    modifyFloat(&number); // Przekazujemy wskaźnik do zmiennej
    
    printf("Wartość po modyfikacji: %.2f\n", number);
    
    return 0;
}