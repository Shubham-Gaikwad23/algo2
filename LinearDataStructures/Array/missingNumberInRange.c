// Find the Missing Number: Given an array containing n distinct numbers in the closed interval [m, n], find the missing one.
 
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

int findMissingNumber(int arr[], int m, int n) {
    assert(m < n);
    int total = 0;
    /* The input array contains all numbers in [m..n] except one missing value.
       The array length is therefore (n - m). Sum the array elements. */
    int size = n - m; // number of elements present in arr
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }

    /* Sum of integers from m to n inclusive = sum(0..n) - sum(0..(m-1)) */
    int sum0ton = (n * (n + 1)) / 2;
    int sum0tom1 = ((m - 1) * m) / 2; // works for m == 0
    int expectedTotal = sum0ton - sum0tom1;
    return expectedTotal - total;
}

int main(void) {
    // Test case 1
    int arr1[] = {0, 1, 3}; // n = 3, numbers should be 0..3, missing 2
    assert(findMissingNumber(arr1, 0, 3) == 2);

    // Test case 2
    int arr2[] = {1, 2, 3, 4, 5}; // n = 5, numbers should be 0..5, missing 0
    assert(findMissingNumber(arr2, 0, 5) == 0);

    // Test case 3
    int arr3[] = {0, 1, 2, 3, 4}; // n = 5, numbers should be 0..5, missing 5
    assert(findMissingNumber(arr3, 0, 5) == 5);

    // Test case 4
    int arr4[] = {0, 2}; // n = 3, numbers should be 0..2, missing 1
    assert(findMissingNumber(arr4, 0, 2) == 1);

    int arr5[] = {3, 4, 5, 6}; // m = 3, n = 7

    printf("All test cases passed!\n");
    return 0;
}