class BSTNode:
	key: int

	def __init__(self, subtree, key: int):
		self.key = key
		self.left = None
		self.right = None
		if subtree:
			while subtree:
				parent = subtree
				if subtree.key > key:
					subtree = subtree.left
				else:
					subtree = subtree.right
			if parent.key > key:
				parent.left = self
			else:
				parent.right = self

	def __str__(self):
		return f"Key: {self.key}"

def find_dis(root: BSTNode, n1: int, n2: int):
	x=y=root
	depth_x = depth_y = common_dis = 0
	while x.key != n1 or y.key != n2:
		if x.key != n1:
			if x.key > n1:
				x = x.left
			else:
				x = x.right
			depth_x += 1
		if y.key != n2:
			if y.key > n2:
				y = y.left
			else:
				y = y.right
			depth_y += 1
		if x.key == y.key:
			common_dis += 1

	return depth_x + depth_y - 2 * common_dis

def in_order(subtree):
		if subtree:
			in_order(subtree.left)
			print(subtree.key, end=' ')
			in_order(subtree.right)

def search(subtree, key):
	while subtree and subtree.key != key:
		if subtree.key > key:
			subtree = subtree.left
		else:
			subtree = subtree.right
	return subtree


def main():
	root = BSTNode(None, 10)
	BSTNode(root, 5)
	BSTNode(root, 15)
	BSTNode(root, 1)
	BSTNode(root, 6)
	BSTNode(root, 13)
	BSTNode(root, 17)
	BSTNode(root, 16)
	x = int(input("Enter x: "))
	if not search(root, x):
		raise Exception(f"Node with key {x} do not exists")
	y = int(input("Enter y: "))
	if not search(root, y):
		raise Exception(f"Node with key {y} do not exists")

	print(f"Distance between {x} and {y} is {find_dis(root, x, y)}")


if __name__ == '__main__':
	main()