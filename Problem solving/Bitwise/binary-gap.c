// https://leetcode.com/problems/binary-gap/
#include <math.h>

int binaryGap(int n) {
    int exp = 0;
    int mask = pow(2, exp);
    int gap = 0;
    int one_pos=-1;
    int current_gap;
    
    while(mask <= n) {
        if(n & mask) {
            if(one_pos == -1) 
                one_pos = exp;
            else {
                current_gap = exp - one_pos;
                if(current_gap > gap)
                    gap = current_gap;
                one_pos = exp;
            }
        } 
    
        ++exp;
        mask = pow(2, exp);
    }
    
    return gap;
}
