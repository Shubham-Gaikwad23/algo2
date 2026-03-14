#include <stdio.h>

void insertion_sort(int [], int);
int test_cases();
int verify_sorted(int [], int);
void print_arr(int arr[], int n);

/**
 * Alogrithm INSERTION-SORT(A, n):
 * 1. for i = 2 to n
 * 2.   key = A[i]
 * 3.   // Insert A[i] into the sorted subarray A[1 : i – 1].
 * 4.   j = i – 1
 * 5.   while j > 0 and A[j] > key
 * 6.       A[j + 1] = A[j]
 * 7.       j = j – 1
 * 8.   A[j + 1] = key
 * 
 * Note: Index start at 1 instead of 0 in pseudo code
 */
void insertion_sort(int arr[], int n) {
    int i, j, key;

    // Base case
    if (n == 1) {
        return;
    }

    for (i = 1; i < n; i++) {
        key = arr[i];
        
        // Insert arr[i] into the sorted subarray arr[0: i - 1]
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place the key in correct place j + 1
        arr[j + 1] = key;
    }
}

/**
 * Print the input array for debugging/learning purpose
 */
void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Test cases
 */
int test_cases() {
    int passed, failed, i;
#define num_cases 5
    int input[num_cases][5] = {
        {1, 2, 4, 5, 6},
        {5, 4, 3, 2, 1},
        {1, 3, 5, 4, 7},
        {10, 48, 8, 74, 42},
        {11, 4, 18, 174, 42}
    };

    passed = failed = 0;
    for (i = 0; i < num_cases; i++) {
        insertion_sort(input[i], 5);
        print_arr(input[i], 5);
        if (verify_sorted(input[i], 5)) {
            passed++;
        } else {
            failed++;
        }
    }
    printf("Passed: %d, failed: %d", passed, failed);
}

/**
 * Test result verification
 */
int verify_sorted(int arr[], int n) {
    int i;

    if (n == 1) {
        return 1;
    }

    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }

    return 1;
}

void main() {
    test_cases();
}
