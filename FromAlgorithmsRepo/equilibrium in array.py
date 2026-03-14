# https://practice.geeksforgeeks.org/problems/equilibrium-point/0
t = int(input())
while t:

    n = int(input())
    a = [int(x) for x in input().split()]

    i = 0
    j = n - 1
    ls, rs = a[i], a[j]

    while ls != rs or i + 1 != j - 1:
        if i < j:
            if ls <= rs:
                i = i + 1
                ls = ls + a[i]
            else:
                j = j - 1
                rs = rs + a[j]
        else:
            break

    if len(a) == 1:
        print(1)
    elif ls == rs:
        print(i + 2)
    else:
        print(-1)

    t = t - 1
