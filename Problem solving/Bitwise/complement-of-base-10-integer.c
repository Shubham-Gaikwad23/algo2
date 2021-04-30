// https://leetcode.com/problems/complement-of-base-10-integer/
#include <math.h>

int bitwiseComplement(int N){
    int mask;
    if(N==0)
        return 1;
    
    mask = pow(2, ( ((int) log2(N)) + 1 )) - 1;
    return ~N & mask;
}
