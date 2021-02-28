class BST:
	class Node:
		def __init__(self, key):
			self.key = key
			self.left = self.right = self.p = None

		def __str__(self):
			return str(self.key)

	def __init__(self):
		self.root = None


	def insert(self, k: int):
		z = self.Node(k)
		y = None
		x = self.root

		while x:
			y = x
			if k < x.key:
				x = x.left
			else:
				x = x.right
		z.p = y
		if y is None:
			self.root = z
		elif k < y.key:
			y.left = z
		else:
			y.right = z

	def transplant(self, u, v):
		if u.p == None:
			self.root = v
		elif u == u.p.left:
			u.p.left = v
		else:
			u.p.right = v
		if v:
			v.p = u.p


	def delete(self, z):
		if z.left is None:
			self.transplant(z, z.right)
		elif z.right is None:
			self.transplant(z, z.left)
		else:
			y = self.min(z.right)
			if y.p is not z:
				self.transplant(y, y.right)
				y.right = z.right
				y.right.p = y
			self.transplant(z, y)
			y.left = z.left
			y.left.p = y
		del z



	def inorder(self, x):
		if x:
			op = self.inorder(x.left)
			op.append(x.key)
			op += self.inorder(x.right)
			return op
		else:
			return []

	def preorder(self, x):
		if x:
			op = []
			op.append(x.key)
			op += self.preorder(x.left)
			op += self.preorder(x.right)
			return op
		else:
			return []

	def postorder(self, x):
		if x:
			op = []
			op = self.postorder(x.left)
			op += self.postorder(x.right)
			op.append(x.key)
			return op
		else:
			return []


	def inorder_iterative(self):
		stack = []
		output = []
		curr = self.root

		while stack or curr:
			if curr:
				stack.append(curr)
				curr = curr.left
			else:
				curr = stack.pop()
				output.append(curr.key)
				curr = curr.right

		return output


	def preorder_iterative(self):
		stack = []
		output = []
		curr = self.root

		while stack or curr:
			if curr:
				output.append(curr.key)
				stack.append(curr)
				curr = curr.left
			else:
				curr = stack.pop()
				curr = curr.right

		return output

	def postorder_iterative(self):
		if self.root:
			stack = [self.root]
		else:
			stack = []
		output = []
		cur = None

		while stack:
			cur = stack.pop()
			output.append(cur.key)

			if cur.left:
				stack.append(cur.left)

			if cur.right:
				stack.append(cur.right)

		output.reverse()
		return output


	def search(self, x, k):
		while x and x.key != k:
			if k < x.key:
				x = x.left
			else:
				x = x.right
		return x

	def min(self, x):
		while x.left:
			x = x.left
		return x

	def max(self, x):
		while x.right:
			x = x.right
		return x

	def successor(self, x):
		if x.right:
			return self.min(x.right)
		y = x.p
		while y and y.right == x:
			x = y
			y = y.p
		return y

	def predecessor(self, x):
		if x.left:
			return self.max(x.right)
		y = x.p
		while y and y.left == x:
			x = y
			y = y.p
		return y


def main():
	tree = BST()
	ch = 1
	while ch:
		print("1. Print BST\n2. Insert\n3. Search\n4. Delete\n0. Exit\n : ", end='')
		ch = int(input())
		print()
		if ch==1:
			sch = 1
			while sch:
				print("1. Preorder\n2. postorder\n3. inorder\n4. preorder_iterative\n5. postorder_iterative\n6. inorder_iterative\n0. Exit\n : ", end='')
				sch = int(input())
				print()
				if sch==1:
					print(tree.preorder(tree.root))
				elif sch==2:
					print(tree.postorder(tree.root))
				elif sch==3:
					print(tree.inorder(tree.root))
				elif sch==4:
					print(tree.preorder_iterative())					
				elif sch==5:
					print(tree.postorder_iterative())					
				elif sch==6:
					print(tree.inorder_iterative())
				elif sch==0:
					pass
				else:
					print("Wrong Choice!\n")


		elif ch==2:
			tree.insert(int(input("Enter key : ")))
		elif ch==3:
			key = int(input("Search key : "))
			if tree.search(tree.root, key):
				print("Node exists")
			else:
				print("Node not found")
		elif ch==4:
			key = int(input("Delete key : "))
			tree.delete(tree.search(tree.root, key))
		elif ch==0:
			pass
		else:
			print("Wrong Choice\n")

if __name__ == '__main__':
	main()
			