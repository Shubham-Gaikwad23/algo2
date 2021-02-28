from typing import List

class Heap:
	"""This is a max heap"""
	def __init__(self, a: List[int]):
		self.a = a
		self.build_max_heap()

	def max_heapify(self, i: int):
		left = (i+1)*2 - 1 
		right = left + 1

		if left < self.size and self.a[i] < self.a[left]:
			largest = left
		else:
			largest = i
		if right < self.size and self.a[largest] < self.a[right]:
			largest = right

		if i != largest:
			self.a[i], self.a[largest] = self.a[largest], self.a[i]
			self.max_heapify(largest)


	def build_max_heap(self):
		self.size = len(self.a)
		last_parent = int(self.size/2) - 1
		for i in range(last_parent, -1, -1):
			self.max_heapify(i)


	def sort(self):
		for i in range(self.size-1, 0, -1):
			self.a[0], self.a[self.size-1] = self.a[self.size-1], self.a[0]
			self.size -= 1
			self.max_heapify(0)

		return self.a


def main():
	a = [int(x) for x in input().split()]
	heap = Heap(a)
	print(heap.sort())

if __name__ == '__main__':
	main()