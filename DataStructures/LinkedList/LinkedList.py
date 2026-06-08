class LinkedList:
	class Node:
		def __init__(self, key: int):
			self.key = key
			self.next = None

	def __init__(self):
		self.head = None

	def __str__(self):
		ret = ""
		cur = self.head
		while cur:
			ret += str(cur.key) + " "
			cur = cur.next
		return ret+"End of list"


	def insert(self, key: int):
		if self.head:
			new_node = self.Node(key)
			new_node.next = self.head
			self.head = new_node
		else:
			self.head = self.Node(key)

	def search(self, key: int):
		cur = self.head
		while cur and cur.key != key:
			cur = cur.next

		return cur

	def delete(self, key: int):
		prev = None
		cur = self.head
		while cur and cur.key != key:
			prev = cur
			cur = cur.next

		if cur:
			if prev is None:
				self.head = cur.next
			elif cur.next is None:
				prev.next = None
			else:
				prev.next = cur.next
			del cur
		else:
			raise Exception("Cannot delete a node which does not exists")

def main():
	lst = LinkedList()
	ch = 1
	while ch:
		print("1. Print LinkedList\n2. Insert\n3. Search\n4. Delete\n0. Exit\n : ", end='')
		ch = int(input())
		print()
		if ch==1:
			print(lst)
		elif ch==2:
			lst.insert(int(input("Enter key : ")))
		elif ch==3:
			key = int(input("Search key : "))
			if lst.search(key):
				print("Node exists")
			else:
				print("Node not found")
		elif ch==4:
			key = int(input("Delete key : "))
			lst.delete(key)
		elif ch==0:
			pass
		else:
			print("Wrong Choice\n")

if __name__ == '__main__':
	main()
			