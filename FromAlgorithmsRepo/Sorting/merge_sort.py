from typing import List
import random

def merge(a: List[int], p: int, q: int, r: int):
    """
    Merge the two sorted sub-lists into single sorted list
    """
    # Out of place: O(n) space allocation
    l = a[p:q]
    r = a[q:r]

    # Starting index for left, right and original list
    i = 0
    j = 0
    k = p

    # Merge the left and right list back to original list
    while i < len(l) and j < len(r):
        if l[i] <= r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1
        k += 1
    
    # Either of the two lists may have left over elements
    # Copy them back to original list
    while i < len(l):
        a[k] = l[i]
        i += 1
        k += 1
    
    while j < len(r):
        a[k] = r[j]
        j += 1
        k += 1
    

def merge_sort(a: List[int], p: int, r: int):
    """
    Recursive merge sort algorithm
    """
    # Base condition: List of length 0 or 1 is already sorted
    if p >= r - 1:
        return

    # Get the mid point
    q = (p + r) // 2

    # Sort the left sub-list recursively
    merge_sort(a, p, q)
    # Sort the right sub-list recursively
    merge_sort(a, q, r)
    # Merge the two sorted sub-list into single sorted list
    merge(a, p, q, r)

def main():
    # Test the algorithm
    for _ in range(100):
        a = random.sample(range(0, 5000), 1000)
        e = a[:]
        merge_sort(a, 0, len(a))
        assert a == sorted(e)

if __name__ == '__main__':
    main()
