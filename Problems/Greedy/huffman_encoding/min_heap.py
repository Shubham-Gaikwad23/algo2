class Heap:
	def __init__(self, a):
		self.a = a
		self.build_max_heap()

	def min_heapify(self, i: int):
		left = (i+1)*2 - 1 
		right = left + 1

		if left < self.size and self.a[i].freq > self.a[left].freq:
			smallest = left
		else:
			smallest = i
		if right < self.size and self.a[smallest].freq > self.a[right].freq:
			smallest = right

		if i != smallest:
			self.a[i], self.a[smallest] = self.a[smallest], self.a[i]
			self.min_heapify(smallest)


	def build_max_heap(self):
		self.size = len(self.a)
		last_parent = int(self.size/2) - 1
		for i in range(last_parent, -1, -1):
			self.min_heapify(i)

	def sort(self):
		for i in range(self.size-1, 0, -1):
			self.a[0], self.a[self.size-1] = self.a[self.size-1], self.a[0]
			self.size -= 1
			self.min_heapify(0)

		return self.a


def main():
	# import random
	# randomlist = random.sample(range(-99, 99), 100)
	# heap = Heap(randomlist)
	# randomlist.sort()
	# res = heap.sort()
	# if res == randomlist:
	# 	print(res)
	# else:
	# 	print("Fail")
	pass



if __name__ == '__main__':
	main()