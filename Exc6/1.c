#include <stdio.h>
#include <stdlib.h>

// Define a union called SovietUnion
union SovietUnion {
    int intValue;
    float floatValue;
    char charValue;
};

int main() {
    // Declare a variable of type SovietUnion
    union SovietUnion SovietUnion;

    // Assign a value to the intValue member of SovietUnion
    SovietUnion.intValue = 10;
    printf("Integer value: %d\n", SovietUnion.intValue);

    // Assign a value to the floatValue member of SovietUnion
    SovietUnion.floatValue = 3.14;
    printf("Float value: %f\n", SovietUnion.floatValue);

    // Assign a value to the charValue member of SovietUnion
    SovietUnion.charValue = 'A';
    printf("Character value: %c\n", SovietUnion.charValue);

    return 0;
}