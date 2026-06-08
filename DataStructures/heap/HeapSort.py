import math
from typing import List


class Heap:
    a: List[int]
    size: int

    def __init__(self, a: List[int]):
        self.a = [math.nan] + a
        self._build_max_heap()

    def heap_sort(self):
        pass

    def _max_heapify(self, i: int):
        l = 2*i
        r = l + 1
        if l <= self.size and self.a[l] > self.a[i]:
            largest = l
        else:
            largest = i
        try:
            if r <= self.size and self.a[r] > self.a[largest]:
                largest = r
        except IndexError:
            print(l, r, i, largest)
            raise
        if largest != i:
            self.a[i], self.a[largest] = self.a[largest], self.a[i]
            self._max_heapify(largest)

    def _build_max_heap(self):
        self.size = len(self.a)
        for i in range(int(self.size / 2), 0, -1):
            self._max_heapify(i)


def main():
    a = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1]  # [int(x) for x in input().split()]
    h = Heap(a)
    print(h.a)


if __name__ == '__main__':
    main()



