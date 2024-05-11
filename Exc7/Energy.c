#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Open the file for reading
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int sum = 0;
    char line[50];
    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        int firstDigit = line[0] - '0';
        int lastDigit = line[strlen(line) - 2] - '0';
        int energyValue = firstDigit * 10 + lastDigit;
        sum += energyValue;
    }

    // Close the file
    fclose(file);

    printf("Sum of energy values: %d\n", sum);

    return 0;
}