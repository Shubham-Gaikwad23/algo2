// Problem Statement: Array Index Computation

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

int rowMajorIndex(int row, int col, int numCols) {
    return (row * numCols) + col;
}

int colMajorIndex(int row, int col, int numRows) {
    return (col * numRows) + row;
}

int main() {
    srand(time(NULL));
    const size_t n = 10;
    const size_t size = n * n;
       
    int arr[n][n];
    int arr2[n][n]; 
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            int val = rand();
            arr[i][j] = val;
            assert(*(&arr[0][0] + rowMajorIndex(i, j, n)) == val);

            arr2[j][i] = val;
            assert(*(&arr2[0][0] + colMajorIndex(i, j, n)) == val);
        }
    }

    return 0;
}
