"""
A practice of Heap sort algorith using max heap data structure
"""

from typing import List
import random

class MaxHeap:
    """
    An object-oriented approach to implementing 
    Max Heap data structure and heap sort algorithm
    """
    def __init__(self, a: List[int]):
        """
        Initialize the data structure
        """
        self.a: List[int] = a
        self.size: int = len(a)
    
    def sort(self):
        """
        Heap sort using max heap DS
        """
        # Find the last internal node in tree
        i = self.size // 2 - 1

        # Re-arrange the tree to satisfy MaxHeap property
        while i >= 0:
            self.heapify(i)
            i -= 1
        
        # Iterate through the tree from last node to first
        while self.size > 1:
            # Swap the root with last node
            # So that largest elemnent is place at the last place
            tmp = self.a[self.size - 1]
            self.a[self.size - 1] = self.a[0]
            self.a[0] = tmp

            # Decrement max heap size while maintaining the heap property
            self.size -= 1
            self.heapify(0)

    def heapify(self, i: int):
        """
        Maintain the max heap property at index i.
        Node at index i may not obey the max heap property.
        The subtree rooted at left and right child of node i are assumed to obey max heap property.
        """
        # Get left and right subtree
        l = (i << 1) + 1
        r = (i << 1) + 2
    
        # Find the largest of three
        largest: int
        if l < self.size and self.a[l] > self.a[i]:
            largest = l
        else:
            largest = i
        if r < self.size and self.a[r] > self.a[largest]:
            largest = r

        # Swap the largest elemnent to root of tree
        if i != largest:
            tmp = self.a[i]
            self.a[i] = self.a[largest]
            self.a[largest] = tmp
            self.heapify(largest)

def main():
    # Test the algorithm
    for _ in range(100):
        a = random.sample(range(0, 5000), 1000)
        e = a[:]
        max_heap = MaxHeap(a)
        max_heap.sort()
        assert max_heap.a == sorted(e)

if __name__ == '__main__':
    main()
