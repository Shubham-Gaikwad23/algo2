from min_heap import Heap
from math import inf as infinity

class PriorityQueue(Heap):
	def __init__(self, a):
		super().__init__(a)

	# def __str__(self):
	# 	return str(self.a)

	def insert(self, obj):
		key = obj.freq
		obj.freq = infinity
		self.size += 1
		self.a.append(obj)
		self.decrease_key(self.size-1, key)

	def minimum(self):
		if self.size < 1:
			return None
		return self.a[0]

	def extract_min(self):
		if self.size < 1:
			raise Exception("Heap underflow")
		min_item = self.a[0]
		self.a[0] = self.a[self.size-1]
		self.size -= 1
		del self.a[-1]
		self.min_heapify(0)
		return min_item

	def decrease_key(self, i:int, key: int):
		if key > self.a[i].freq:
			raise Exception("New key larger than current key")

		self.a[i].freq = key
		while i>0 and self.a[int((i+1)/2) - 1].freq > self.a[i].freq:
			self.a[i], self.a[int((i+1)/2) - 1] = self.a[int((i+1)/2) - 1], self.a[i]
			i = int((i+1)/2) - 1

def main():
	q = PriorityQueue([])
	ch = 1
	while ch:
		print("1. Print Queue\n2. Insert\n3. Decrease Key\n4. minimum\n5. Extract min\n0. Exit\n : ", end='')
		ch = int(input())
		print()
		if ch==1:
			print(q)
		elif ch==2:
			q.insert(int(input("Enter key : ")))
		elif ch==3:
			index = int(input("Decrease key at index : "))
			q.decrease_key(index, int(input(f"Old key = {q.a[index]} Enter new key : ")))
		elif ch==4:
			print("Maximum key is", q.minimum())
		elif ch==5:
			print(f"Key = {q.extract_min()} removed")
		elif ch==0:
			pass
		else:
			print("Wrong Choice\n")


if __name__ == '__main__':
	main()