#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Prepare a program in which instead of printing "Hello, World" to the console,
// the user will be able to enter their name. You can use the scanf function for this,
// where you will need to pass a pointer to the variable. But for now, don't worry about that.
int main() {
    char name[100];
    
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Hello, %s!\n", name);
 
    printf("Press any key to continue...");
    getch();
    
    return 0;
}