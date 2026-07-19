"""
A practice of quick sort algorithm
"""

from typing import List
import random

def quick_sort(a: List[int], p, r):
    """
    Recursive quick sort algorithm
    """
    if p < r:
        q = partition(a, p, r)
        quick_sort(a, p, q - 1)
        quick_sort(a, q + 1, r)

def partition(a: List[int], p, r):
    """
    Partition the array
    """
    pivot = a[r]
    i = p - 1
    j = p

    while j < r:
        if a[j] <= pivot:
            i += 1
            tmp = a[j]
            a[j] = a[i]
            a[i] = tmp
        j += 1
    
    i += 1
    tmp = a[i]
    a[i] = a[r]
    a[r] = tmp
    return i

def main():
    # Test the algorithm
    for _ in range(100):
        a = random.sample(range(0, 5000), 1000)
        e = a[:]
        quick_sort(a, 0, len(a) - 1)
        assert a == sorted(e)

if __name__ == '__main__':
    main()
