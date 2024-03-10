#include <stdio.h>
#include <stdlib.h>

//- Define a structure called `Point` that stores the coordinates of a point on a plane (x, y).
//- Write a function that takes a pointer to the `Point` structure and changes its coordinate values.
//- Create an instance of `Point` and change its coordinates using the function,
//   then print the modified coordinates.
//- Then create a structure called `Rectangle`.
//- Write a function that takes a `Rectangle` structure and calculates its area and perimeter.


// Define a structure called `Point` that stores the coordinates of a point on a plane (x, y).
struct Point {
    int x;
    int y;
};

// Write a function that takes a pointer to the `Point` structure and changes its coordinate values.
void changeCoordinates(struct Point* point, int newX, int newY) {
    point->x = newX;
    point->y = newY;
}

// Create a structure called `Rectangle`.
struct Rectangle {
    int width;
    int height;
};

// Write a function that takes a `Rectangle` structure and calculates its area and perimeter.
void calculateRectangle(struct Rectangle* rectangle, int* area, int* perimeter) {
    *area = rectangle->width * rectangle->height;
    *perimeter = 2 * (rectangle->width + rectangle->height);
    printf("Area: %d\n", *area);
    printf("Perimeter: %d\n", *perimeter);
}

int main(int argc, char const *argv[]) {
    // Create an instance of Point
    struct Point point;
    point.x = 3;
    point.y = 5;

    // Change the coordinates of the Point
    changeCoordinates(&point, 7, 9);

    // Print the modified coordinates
    printf("Modified coordinates: (%d, %d)\n", point.x, point.y);

    // Create an instance of Rectangle
    struct Rectangle rectangle;
    rectangle.width = 4;
    rectangle.height = 6;
    int area, perimeter;

    // Calculate the area and perimeter of the Rectangle
    calculateRectangle(&rectangle, &area, &perimeter);

    // Note: The following line seems unnecessary and might lead to undefined behavior.
    // char* nic;
    // scanf("%s", nic);

    return 0;
}
