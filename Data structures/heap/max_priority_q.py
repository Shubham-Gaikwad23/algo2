from heap_sort import Heap
from math import inf as infinity

class PriorityQueue(Heap):
	def __init__(self):
		super().__init__([])

	def __str__(self):
		return str(self.a)

	def insert(self, key: int):
		self.size += 1
		self.a.append(-infinity)
		self.increase_key(self.size-1, key)

	def maximum(self):
		if self.size < 1:
			return None
		return self.a[0]

	def extract_max(self):
		if self.size < 1:
			raise Exception("Heap underflow")
		max_item = self.a[0]
		self.a[0] = self.a[self.size-1]
		self.size -= 1
		del self.a[-1]
		self.max_heapify(0)
		return max_item

	def increase_key(self, i:int, key: int):
		if key < self.a[i]:
			raise Exception("New key smaller than current key")

		self.a[i] = key
		while i>0 and self.a[int((i+1)/2) - 1] < self.a[i]:
			self.a[i], self.a[int((i+1)/2) - 1] = self.a[int((i+1)/2) - 1], self.a[i]
			i = int((i+1)/2) - 1


def main():
	q = PriorityQueue()
	ch = 1
	while ch:
		print("1. Print Queue\n2. Insert\n3. Increse Key\n4. Maximum\n5. Extract max\n0. Exit\n : ", end='')
		ch = int(input())
		print()
		if ch==1:
			print(q)
		elif ch==2:
			q.insert(int(input("Enter key : ")))
		elif ch==3:
			index = int(input("Increse key at index : "))
			q.increase_key(index, int(input(f"Old key = {q.a[index]} Enter new key : ")))
		elif ch==4:
			print("Maximum key is", q.maximum())
		elif ch==5:
			print(f"Key = {q.extract_max()} removed")
		elif ch==0:
			pass
		else:
			print("Wrong Choice\n")


if __name__ == '__main__':
	main()