class Solution:

    def maxRepeating(self, arr, n, k):
        # code here
        if n == 1:
            return arr[0]
        arr.sort()
        ans = arr[0]
        max_len = 0
        ans_curr = arr[0]

        max_len_curr = 0
        for i in range(n):
            if arr[i] == ans_curr:
                max_len_curr += 1
            else:
                if max_len < max_len_curr:
                    ans = ans_curr
                    max_len = max_len_curr
                max_len_curr = 1
                ans_curr = arr[i]
        return ans