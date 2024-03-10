#include <stdio.h>
#include <stdlib.h>

//- Declare a variable of type `int` and assign a value to it.
//- Create a pointer to this variable.
//- Modify the value of the variable using the pointer.
//- Print the value of the variable in two ways: directly and through the pointer.

int main(int argc, char const *argv[])
{
    
    int varra = 10; 
    int *poinNotClick = &varra; 

    *poinNotClick = 20; 

    printf("Value of variable: %d\n", varra); 
    printf("Value of variable through pointer: %d\n", *poinNotClick); 
    
    return 0;
}
