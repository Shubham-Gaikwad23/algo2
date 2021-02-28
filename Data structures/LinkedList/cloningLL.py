class LinkedList:
	class Node:
		def __init__(self, key: int):
			self.key = key
			self.next = None
			self.ran = None

	def __init__(self):
		self.head = None


	def insert(self, key: int):
		new_head = self.Node(key)
		new_head.next = self.head
		self.head = new_head

	def print(self):
		cur = self.head
		while cur:
			random = None
			if cur.ran:
				random = cur.ran.key
			print(f"{cur.key}--{random}", end='\t')
			cur=cur.next
		print()

	def clone_hash(self):
		clone = self.Node(self.head.key)
		cur_o = self.head.next
		cur_c = clone
		table = {self.head: clone}
		while cur_o:
			cur_c.next = self.Node(cur_o.key)
			table[cur_o] = cur_c.next
			cur_o = cur_o.next
			cur_c = cur_c.next

		cur_c = clone
		cur_o = self.head
		while cur_o:
			if cur_o.ran:
				table[cur_o].ran = table[cur_o.ran]
			cur_o = cur_o.next

		cloned_list = LinkedList()
		cloned_list.head = clone
		return cloned_list

	def clone(self):
		cur = self.head
		while cur:
			tmp = self.Node(cur.key)
			tmp.next = cur.next
			if cur.next:
				cur.next = tmp
			else:
				cur.next = None
			if cur.next:
				cur = cur.next.next
			else:
				cur = None

		cur = self.head
		while cur:
			if cur.ran:
				cur.next.ran = cur.ran.next
			cur = cur.next.next

		cloned_list = LinkedList()
		cloned_list.head = self.head.next

		ori = self.head
		clo = cloned_list.head
		while ori:
			ori.next = ori.next.next
			clo.next = clo.next.next
			ori = ori.next
			clo = clo.next

		return cloned_list


def main():
	lst = LinkedList()
	lst.insert(4)
	lst.insert(7)
	lst.insert(-2)
	lst.insert(10)

	lst.head.ran = lst.head.next.next
	lst.head.next.ran = lst.head
	lst.head.next.next.next.ran = lst.head.next.next.next

	lst.print()
	lst.clone().print()



if __name__ == '__main__':
	main()
