#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROD_LEN 60

int memoized;

int rod_cutting(int *price, int len, int* optimal_profit) {
    int profit = -1;
    if (len == 0) {
        return 0;
    }
    
    if (memoized && optimal_profit[len] != 0) {
        return optimal_profit[len];
    }

    for(int cut = 0; cut < len; cut++) {
        int p = price[cut] + rod_cutting(price, len - cut - 1, optimal_profit);
        if (p > profit) {
            profit = p;
        }
    }

    optimal_profit[len] = profit;
    return profit;
}

int rod_cutting_bu(int *price, int len) {
    if (len == 0) {
        return 0;
    }

    // Allocate memory for memoization
    int *optimal_profit = malloc(sizeof(int) * len + 1);
    memset(optimal_profit, 0, sizeof(int) * len + 1);
    
    // Start computing optimal profit from length 1
    // where optimal profit for length 0 is 0 is a base condition
    for (int clen = 1; clen <= len; clen++) {
        
        // Compute profit at all cut location
        // from cut 0 that is cut of length 1
        // to cut = clen - 1 which is no cut at all
        for (int cut = 0; cut < clen; cut++) {
            
            // price[cut] is the price of rot of length cut + 1
            // we already computed optimal profit of rod length clen - cut
            // in the last iteration. 
            int x = price[cut] + optimal_profit[clen - cut - 1];
            if (x > optimal_profit[clen]) {
                optimal_profit[clen] = x;
            }
        }
    }
    
    int op = optimal_profit[len];
    free(optimal_profit);
    return op;
}

int main() {
    int price[ROD_LEN] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 34, 37, 38, 45, 45, 48, 52, 58, 62, 65, \
                     69, 72, 73, 74, 81, 81, 84, 88, 94, 98, 101, 102, 109, 109, 112, 116, 122, 126, 129, 133, \
                     136, 137, 138, 145, 145, 148, 152, 158, 162, 165, 169, 172, 173, 174, 181, 181, 184, 188, 194, 198}; 
    
    for(int len = 1; len <= ROD_LEN; len++) {

        int optimal_profit[ROD_LEN + 1] = {0};
        printf("Length: %d\n", len);

        // No memoized
        clock_t start = clock();
        memoized = 0;
        int profit = rod_cutting(price, len, optimal_profit);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Runtime without memoized: %f, profit: %d\n", time_taken, profit);
        
        // Memoized
        memset(optimal_profit, 0, sizeof(int) * ROD_LEN + 1);
        start = clock();
        memoized = 1;
        profit = rod_cutting(price, len, optimal_profit);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Runtime with memoized: %f, profit: %d\n", time_taken, profit);
        
        // Bottom up approach (Memoized)
        start = clock();
        profit = rod_cutting_bu(price, len);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Runtime BU memoized: %f, profit: %d\n", time_taken, profit);
        printf("----------------------------------\n");
    }
    return 0;
}



/**
Length: 1
Runtime without memoized: 0.000002, profit: 1
Runtime with memoized: 0.000000, profit: 1
Runtime BU memoized: 0.000001, profit: 1
----------------------------------
Length: 2
Runtime without memoized: 0.000000, profit: 5
Runtime with memoized: 0.000000, profit: 5
Runtime BU memoized: 0.000001, profit: 5
----------------------------------
Length: 3
Runtime without memoized: 0.000000, profit: 8
Runtime with memoized: 0.000001, profit: 8
Runtime BU memoized: 0.000001, profit: 8
----------------------------------
Length: 4
Runtime without memoized: 0.000001, profit: 10
Runtime with memoized: 0.000001, profit: 10
Runtime BU memoized: 0.000001, profit: 10
----------------------------------
Length: 5
Runtime without memoized: 0.000001, profit: 13
Runtime with memoized: 0.000001, profit: 13
Runtime BU memoized: 0.000001, profit: 13
----------------------------------
Length: 6
Runtime without memoized: 0.000001, profit: 17
Runtime with memoized: 0.000001, profit: 17
Runtime BU memoized: 0.000001, profit: 17
----------------------------------
Length: 7
Runtime without memoized: 0.000002, profit: 18
Runtime with memoized: 0.000001, profit: 18
Runtime BU memoized: 0.000002, profit: 18
----------------------------------
Length: 8
Runtime without memoized: 0.000003, profit: 22
Runtime with memoized: 0.000001, profit: 22
Runtime BU memoized: 0.000001, profit: 22
----------------------------------
Length: 9
Runtime without memoized: 0.000005, profit: 25
Runtime with memoized: 0.000001, profit: 25
Runtime BU memoized: 0.000001, profit: 25
----------------------------------
Length: 10
Runtime without memoized: 0.000009, profit: 30
Runtime with memoized: 0.000002, profit: 30
Runtime BU memoized: 0.000002, profit: 30
----------------------------------
Length: 11
Runtime without memoized: 0.000016, profit: 34
Runtime with memoized: 0.000002, profit: 34
Runtime BU memoized: 0.000001, profit: 34
----------------------------------
Length: 12
Runtime without memoized: 0.000032, profit: 37
Runtime with memoized: 0.000001, profit: 37
Runtime BU memoized: 0.000001, profit: 37
----------------------------------
Length: 13
Runtime without memoized: 0.000060, profit: 39
Runtime with memoized: 0.000001, profit: 39
Runtime BU memoized: 0.000002, profit: 39
----------------------------------
Length: 14
Runtime without memoized: 0.000101, profit: 45
Runtime with memoized: 0.000001, profit: 45
Runtime BU memoized: 0.000002, profit: 45
----------------------------------
Length: 15
Runtime without memoized: 0.000243, profit: 46
Runtime with memoized: 0.000002, profit: 46
Runtime BU memoized: 0.000002, profit: 46
----------------------------------
Length: 16
Runtime without memoized: 0.000405, profit: 50
Runtime with memoized: 0.000002, profit: 50
Runtime BU memoized: 0.000001, profit: 50
----------------------------------
Length: 17
Runtime without memoized: 0.000848, profit: 53
Runtime with memoized: 0.000003, profit: 53
Runtime BU memoized: 0.000003, profit: 53
----------------------------------
Length: 18
Runtime without memoized: 0.001760, profit: 58
Runtime with memoized: 0.000003, profit: 58
Runtime BU memoized: 0.000003, profit: 58
----------------------------------
Length: 19
Runtime without memoized: 0.003461, profit: 62
Runtime with memoized: 0.000002, profit: 62
Runtime BU memoized: 0.000003, profit: 62
----------------------------------
Length: 20
Runtime without memoized: 0.007872, profit: 65
Runtime with memoized: 0.000002, profit: 65
Runtime BU memoized: 0.000002, profit: 65
----------------------------------
Length: 21
Runtime without memoized: 0.013276, profit: 69
Runtime with memoized: 0.000002, profit: 69
Runtime BU memoized: 0.000002, profit: 69
----------------------------------
Length: 22
Runtime without memoized: 0.032479, profit: 72
Runtime with memoized: 0.000004, profit: 72
Runtime BU memoized: 0.000003, profit: 72
----------------------------------
Length: 23
Runtime without memoized: 0.053283, profit: 74
Runtime with memoized: 0.000003, profit: 74
Runtime BU memoized: 0.000002, profit: 74
----------------------------------
Length: 24
Runtime without memoized: 0.094373, profit: 77
Runtime with memoized: 0.000003, profit: 77
Runtime BU memoized: 0.000002, profit: 77
----------------------------------
Length: 25
Runtime without memoized: 0.203110, profit: 81
Runtime with memoized: 0.000004, profit: 81
Runtime BU memoized: 0.000003, profit: 81
----------------------------------
Length: 26
Runtime without memoized: 0.504793, profit: 82
Runtime with memoized: 0.000005, profit: 82
Runtime BU memoized: 0.000004, profit: 82
----------------------------------
Length: 27
Runtime without memoized: 1.008799, profit: 86
Runtime with memoized: 0.000005, profit: 86
Runtime BU memoized: 0.000004, profit: 86
----------------------------------
Length: 28
Runtime without memoized: 1.572573, profit: 90
Runtime with memoized: 0.000005, profit: 90
Runtime BU memoized: 0.000004, profit: 90
----------------------------------
Length: 29
Runtime without memoized: 3.476720, profit: 94
Runtime with memoized: 0.000005, profit: 94
Runtime BU memoized: 0.000004, profit: 94
----------------------------------
Length: 30
Runtime without memoized: 6.528380, profit: 98
Runtime with memoized: 0.000011, profit: 98
Runtime BU memoized: 0.000006, profit: 98
----------------------------------
Length: 31
Runtime without memoized: 13.073903, profit: 101
Runtime with memoized: 0.000006, profit: 101
Runtime BU memoized: 0.000005, profit: 101
 */
