# https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0

t = int(input())
while t:
    n, d = input().split()
    n, d = int(n), int(d)
    a = [int(x) for x in input().split()]
    d = d % n
    for i in range(-(n - d), d, 1):
        print(a[i], end=' ')
    print()
    t = t - 1
