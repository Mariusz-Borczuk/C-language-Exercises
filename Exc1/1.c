#include <stdio.h>
#include <stdlib.h>

// Prepare a program in which instead of printing "Hello, World" to the console,
// the user will be able to enter their name. You can use the scanf function for this,
// where you will need to pass a pointer to the variable. But for now, don't worry about that.
int main() {
    char name[100];
    char* nic ;
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Hello, %s!\n", name);
    //wait for any key to be pressed
    printf("Press any key to continue...");
    scanf("%s", nic);
    
    return 0;
}