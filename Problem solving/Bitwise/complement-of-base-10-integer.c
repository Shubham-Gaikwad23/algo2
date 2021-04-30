// https://leetcode.com/problems/complement-of-base-10-integer/
#include <math.h>

int getMask(int n) {
    int bits = ((int) log2(n)) +1;
    return pow(2, bits) - 1;
}

int bitwiseComplement(int N){
    if(N==0)
        return 1;
    
    int mask = getMask(N);
    return ~N&mask;
}
