class Node:
	def __init__(self, key: int, left=None, right=None, h=-1):
		self.key = key
		self.left = left
		self.right = right
		self.h = h


class AVLTree:	
	def __init__(self, key: int):
		self.nil = Node(key=None)
		self.root = Node(key, left=self.nil, right=self.nil, h=0)


	def insert(self, subtree, key: int):
		if subtree is self.nil:
			return Node(key, left=self.nil, right=self.nil, h=0)
		elif key < subtree.key:
			subtree.left = self.insert(subtree.left, key)
		else:
			subtree.right = self.insert(subtree.right, key)

		subtree.h = max(subtree.left.h, subtree.right.h) + 1
		bal_fac = subtree.left.h - subtree.right.h

		if bal_fac > 1 and key < subtree.left.key:
			return self.rotate_right(subtree)

		if bal_fac < -1 and key > subtree.right.key: 
			return self.rotate_left(subtree) 

		if bal_fac > 1 and key > subtree.left.key: 
			subtree.left = self.rotate_left(root.left) 
			return self.rotate_right(root) 

		if bal_fac < -1 and key < subtree.right.key: 
			subtree.right = self.rotate_right(subtree.right) 
			return self.rotate_left(subtree) 
  
        return subtree 

	def rotate_left(self, z): 
		y = z.right 
		T2 = y.left 

		# Perform rotation 
		y.left = z 
		z.right = T2 

		# Update heights 
		z.height = 1 + max(self.getHeight(z.left), 
		                 self.getHeight(z.right)) 
		y.height = 1 + max(self.getHeight(y.left), 
		                 self.getHeight(y.right)) 

		# Return the new root 
		return y 
  
    def rotate_left(self, z): 
  
        y = z.left 
        T3 = y.right 
  
        # Perform rotation 
        y.right = z 
        z.left = T3 
  
        # Update heights 
        z.height = 1 + max(self.getHeight(z.left), 
                        self.getHeight(z.right)) 
        y.height = 1 + max(self.getHeight(y.left), 
                        self.getHeight(y.right)) 
  
        # Return the new root 
        return y 


		# p = self.nil
		# cur = self.root
		# while cur is not self.nil:
		# 	p = cur
		# 	if cur.key > key:
		# 		cur = cur.left
		# 	else:
		# 		cur = cur.right
		# 	p.h += 1
		# if p.key > key:
		# 	p.left = self.Node(key, p=p, left=self.nil, right=self.nil, h=0)
		# 	self.balance(p.left)
		# else:
		# 	p.right = self.Node(key, p=p, left=self.nil, right=self.nil, h=0)
		# 	self.balance(p.right)


	# def balance(self, leaf):
	# 	x = leaf
	# 	y = self.nil
	# 	z = None
	# 	while x is not self.nil and x.left.h - x.right.h not in (2, -2):
	# 		z = y
	# 		y = x
	# 		x = x.p

	# 	if x is not self.nil:
	# 		if x.left is y and y.left is z:
	# 			self.rotate_right(x)
	# 			# y = x
	# 			# x = x.p
	# 			# while x is not self.nil:
	# 			# 	x.h = max(x.left.h, x.right.h) + 1
	# 			# 	y = x
	# 			# 	x = x.p

	# 		elif x.right is y and y.right is z:
	# 			self.rotate_left(x)
	# 			# y = x
	# 			# x = x.p
	# 			# while x is not self.nil:
	# 			# 	x.h = max(x.left.h, x.right.h) + 1
	# 			# 	y = x
	# 			# 	x = x.p

	# 		elif x.left is y and y.right is z:
	# 			self.rotate_left(y)
	# 			self.rotate_right(x)

	# 		elif x.right is y and y.left is z:
	# 			self.rotate_right(y)
	# 			self.rotate_left(x)
	# 	self.update_height(self.root)
		

	# def update_height(self, x):
	# 	if x is self.nil:
	# 		return -1
	# 	else:
	# 		x.h = max(self.update_height(x.left), self.update_height(x.right)) + 1
	# 		return x.h


	# def rotate_right(self, x):
	# 	y = x.left
	# 	x.left = y.right
	# 	if y.right is not self.nil:
	# 		y.right.p = x
	# 	y.p = x.p
	# 	if x.p is self.nil:
	# 		self.root = y
	# 	elif x is x.p.left:
	# 		x.p.left = y
	# 	else:
	# 		x.p.right = y
	# 	y.right = x
	# 	x.p = y

	# def rotate_left(self, x):
	# 	y = x.right
	# 	x.right = y.left
	# 	if y.left is not self.nil:
	# 		y.left.p = x
	# 	y.p = x.p
	# 	if x.p is self.nil:
	# 		self.root = y
	# 	elif x is x.p.left:
	# 		x.p.left = y
	# 	else:
	# 		x.p.right = y
	# 	y.left = x
	# 	x.p = y
			

	# def inorder(self, subtree):
	# 	if subtree is not self.nil:
	# 		self.inorder(subtree.left)
	# 		print(f"Key: {subtree.key} Left: {subtree.left} Right {subtree.right}")
	# 		self.inorder(subtree.right)
		
	# def is_balanced(self, subtree):
	# 	if subtree is self.nil:
	# 		return True
	# 	else:
	# 		if subtree.left.h - subtree.right.h in (0, 1, -1):
	# 			left_bal_fac = self.is_balanced(subtree.left)
	# 			right_bal_fac = self.is_balanced(subtree.right)
	# 			if left_bal_fac and right_bal_fac:
	# 				return True
	# 			else:
	# 				return False
	# 		else:
	# 			print(f"Subtree: {subtree.h} Left: {subtree.left.h} Right: {subtree.right.h}")
	# 			return False

def main():
	import random
	for i in range(20):
		randomlist = set(random.sample(range(1, 100), 35))
		avl = AVLTree(randomlist.pop())
		for x in randomlist:
			avl.insert(x)
		if not avl.is_balanced(avl.root):
			break


	# avl = AVLTree(15)
	# avl.insert(25)
	# avl.insert(20)
	# print(avl.is_balanced(avl.root))
	
	# x = AVLTree(15)
	# x.insert(25)
	# x.root.right.right = x.Node(key=30, left=x.nil, right=x.nil, p=x.root.right, h=0)
	# x.root.h = 2
	# x.root.right.h = 1
	# print(x.is_balanced(x.root))


if __name__ == '__main__':
	main()
