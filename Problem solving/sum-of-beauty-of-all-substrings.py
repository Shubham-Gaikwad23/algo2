# https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

from collections import defaultdict
from math import inf
class Solution:
    def get_beauty(self, substr: str) -> int:
        count = defaultdict(lambda: 0)
        for c in substr:
            count[c] += 1
        
        if len(count) < 2:
            return 0
        
        x1, x2 = inf, -inf
        for key, val in count.items():
            if x1 > val:
                x1 = val
            if x2 < val:
                x2 = val
        
        return x2 - x1
        
    
    def beautySum(self, s: str) -> int:
        beauty_table = dict()
        ans = 0
        for substr_len in range(3, len(s)+1):
            for i in range(len(s) - substr_len + 1):
                substr = s[i:substr_len+i]
                # print(substr)
                # continue
                beauty = 0
                if substr in beauty_table:
                    beauty = beauty_table[substr]
                else:
                    beauty = self.get_beauty(substr)
                    beauty_table[substr] = beauty
                ans += beauty
        
        return ans
