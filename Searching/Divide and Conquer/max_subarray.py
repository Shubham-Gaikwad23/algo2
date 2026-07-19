import math


def max_crossing(a, low, mid, high):
    max_left = max_right = mid
    left_sum = -math.inf
    sum = 0
    for i in range(mid, low-1, -1):
        sum += a[i]
        if sum > left_sum:
            max_left = i
            left_sum = sum
    right_sum = -math.inf
    sum = 0
    for j in range(mid + 1, high + 1):
        sum += a[j]
        if sum > right_sum:
            max_right = j
            right_sum = sum
    return max_left, max_right, left_sum + right_sum


def max_subarray(a: list, low: int, high: int) -> (int, int, int):
    if low == high:
        return low, high, a[low]
    else:
        mid = int((low + high) / 2)
        left_low, left_high, left_sum = max_subarray(a, low, mid)
        right_low, right_high, right_sum = max_subarray(a, mid + 1, high)
        cross_low, cross_high, cross_sum = max_crossing(a, low, mid, high)

        if left_sum >= right_sum >= cross_sum:
            return left_low, left_high, left_sum
        elif right_sum >= left_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum


def main():
    t = int(input())
    while t:
        a = [int(x) for x in input().split()]
        # for i in range(len(a)):
        #     print(f"{i}:{a[i]}", end=' ')
        # print()
        print(max_subarray(a, 0, len(a) - 1))
        t = t - 1


if __name__ == '__main__':
    main()
