# https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
def subArraySum(arr, n, Sum):
    Map = {}
    curr_sum = 0

    for i in range(0, n):
        curr_sum = curr_sum + arr[i]
        if curr_sum == Sum:
            print(1, i + 1)
            return
        if (curr_sum - Sum) in Map:
            print(Map[curr_sum - Sum] + 1 + 1, i + 1)
            return
        Map[curr_sum] = i
    print(-1)


t = int(input())
while t:
    n, rs = input().split()
    n, rs = int(n), int(rs)
    input_line = input().split()
    a = [int(x) for x in input_line]
    subArraySum(a, n, rs)
    t = t - 1
