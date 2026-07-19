# https://practice.geeksforgeeks.org/problems/majority-element/0
t = int(input())
while t:
    n = int(input())
    a = [int(x) for x in input().split()]
    count = {}
    for i in a:
        if count.get(i) is None:
            count[i] = 1
        else:
            count[i] = count[i] + 1
            if count[i] > n / 2:
                print(i)
                break
    else:
        print(-1)
    t = t - 1
