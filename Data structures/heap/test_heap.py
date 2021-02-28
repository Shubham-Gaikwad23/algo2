import random
from .heap_sort import Heap
def test_heap_sort():
	randomlist = random.sample(range(-99, 99), 100)
	heap = Heap(randomlist)
	randomlist.sort()
	assert heap.sort() == randomlist
