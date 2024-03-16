#include <stdio.h>
#include <stdlib.h>

void displayPascalTriangle(int N) {
    int** triangle = (int**)malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

int main() {
    int N;
    printf("Enter the height of Pascal's triangle: ");
    scanf("%d", &N);

    displayPascalTriangle(N);
    //wait 3sec
    printf("\nWaiting for key press...\n");
    scanf("%d");    

    return 0;
}