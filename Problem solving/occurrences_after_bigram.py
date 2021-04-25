# https://leetcode.com/problems/occurrences-after-bigram/
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        terms = text.split(' ')
        ans = []
        if 0 <= len(terms) <= 2:
            return ans
        
        l1 = terms[0];
        l2 = terms[1];
        for term in terms[2:]:
            if l1 == first and l2 == second:
                ans.append(term)
            l1 = l2
            l2 = term
        
        return ans
