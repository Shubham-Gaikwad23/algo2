# https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
t = int(input())
while t:
    n = int(input())
    s = 0
    input_line = input().split()
    for x in input_line:
        s = s + int(x)
    sum = int((n * (n + 1)) / 2)
    x = sum - s;
    print(x)
    t = t - 1
