#include <stdio.h>
#include <stdlib.h>

/* Generate all string permutations

Goal: Write a C program that generates all permutations of a given sequence (e.g. a sequence of numbers). The program should use recursion to generate permutations and display each permutation on the screen.

Requirements:

1. The function should accept as arguments a string (array) and two indices: starting (usually `0`) and ending (length of the string minus `1`).
2. The algorithm should recursively swap elements to generate all possible permutations of the sequence.
3. Once a permutation is generated, the function should display it and then continue generating more permutations until the possibilities are exhausted.
4. It is important to avoid repeating the same permutations if the string contains repeated elements.*/

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int isDuplicate(char *str, int start, int end) {
    for (int i = start; i < end; i++) {
        if (str[i] == str[end]) {
            return 1;
        }
    }
    return 0;
}

void permute(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
    } else {
        for (int i = start; i <= end; i++) {
            if (isDuplicate(str, start, i)) {
                continue;
            }
            swap((str + start), (str + i));
            permute(str, start + 1, end);
            swap((str + start), (str + i)); // backtrack
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    printf("Permutations:\n");
    permute(str, 0, n - 1);

    printf("Press any key to continue...\n");
    scanf("%d");
    return 0;
}