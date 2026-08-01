// Find the Missing Number: Given an array containing n distinct numbers in the range ([0, n]), find the missing one.
// Optimal Approach: Subtract the sum of the array elements from the expected mathematical n(n+1) / 2.

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

// Define a macro that passes __LINE__ and __FILE__ automatically
#define assert(cond) _assert((cond), __LINE__, __FILE__)

// Helper function
void _assert(bool cond, int ln, const char *file) {
    if (!cond) {
        printf("Assertion failure at %s:%d\n", file, ln);
        exit(1); // terminate the program
    }
}

int findMissingNumber(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    int expectedTotal = (n * (n + 1)) / 2;
    return expectedTotal - total;
}

void main(void) {
    // Test case 1
    int arr1[] = {0, 1, 3}; // n = 3, numbers should be 0..3, missing 2
    assert(findMissingNumber(arr1, 3) == 2);

    // Test case 2
    int arr2[] = {1, 2, 3, 4, 5}; // n = 5, numbers should be 0..5, missing 0
    assert(findMissingNumber(arr2, 5) == 0);

    // Test case 3
    int arr3[] = {0, 1, 2, 3, 4}; // n = 5, numbers should be 0..5, missing 5
    assert(findMissingNumber(arr3, 5) == 5);

    // Test case 4
    int arr4[] = {0, 2}; // n = 2, numbers should be 0..2, missing 1
    assert(findMissingNumber(arr4, 2) == 1);

    printf("All test cases passed!\n");
}