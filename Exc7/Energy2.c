#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a string is an English adjective
int isAdjective(char *word) {
    // List of English adjectives
    char *adjectives[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int numAdjectives = sizeof(adjectives) / sizeof(adjectives[0]);

    // Convert the word to lowercase for case-insensitive comparison
    for (int i = 0; word[i]; i++) {
        // Convert the character to lowercase without toLowerCase() function
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32;
        }

    }

    // Check if the word matches any of the adjectives
    for (int i = 0; i < numAdjectives; i++) {
        if (strcmp(word, adjectives[i]) == 0) {
            return 1; // It's an English adjective
        }
    }
    return 0; // It's not an English adjective
}

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
        char *token = strtok(line, " \t\n"); // Split the line into tokens
        int firstDigitFound = 0;
        int lastDigit = -1; // Initialize last digit to an invalid value

        // Loop through tokens in the line
        while (token != NULL) {// Check if the token is a digit with isdigit()
            if (token[0] >= '0' && token[0] <= '9') { // Check if the token is a digit
                if (!firstDigitFound) {
                    firstDigitFound = 1;
                    sum += (int)(token); // Convert token to integer and add to sum
                }
                lastDigit = (int)(token); // Update last digit
            } else if (isAdjective(token)) { // Check if the token is an English adjective
                if (!firstDigitFound) {
                    firstDigitFound = 1;
                    sum += (int)(token); // Convert token to integer and add to sum
                }
                lastDigit = (int)(token); // Update last digit
            }
            token = strtok(NULL, " \t\n"); // Get the next token
        }

        // Add the last digit if it's valid
        if (lastDigit >= 1 && lastDigit <= 9) {
            sum += lastDigit;
        }
    }

    // Close the file
    fclose(file);

    printf("Sum of energy values: %d\n", sum);

    return 0;
}
