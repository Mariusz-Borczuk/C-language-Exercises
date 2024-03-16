#include <stdio.h>
#include <stdlib.h>
/*### Recursive Binary Search
Objective: Write a recursive function in C that performs binary search on a sorted array. The function should return the index of the target element or `-1` if the element is not found in the array.

Requirements:
1. The function should take the array (pointer to the first element), 
left index, right index, and the value of the target element as arguments.
2. Binary search involves dividing the array into two parts and 
checking whether the target element is in the left or right half of the array, 
and then recursively repeating the process for the appropriate part.
3. Make sure the array is sorted before starting the search.*/
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is in the middle of the array
        if (arr[mid] == target) {
            return mid;
        }

        // If the element is smaller than the middle element, search in the left half
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // Otherwise, search in the right half
        return binarySearch(arr, mid + 1, right, target);
    }

    // Element not found
    return -1;
}

int main() {
    // make dynamic array
    int arr[10];
    //fill the array with random two-digit numbers
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 90 + 10; // generates a random number between 10 and 99
    }
    //sort the array
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    //print the array
    for (int i = 0; i < 10; i++) {
        printf("\n""%d ", arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nGive the target number:");
    int target;
    scanf("%d", &target);
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    printf("Press any key to continue...\n");
    scanf("%d");
    return 0;
}