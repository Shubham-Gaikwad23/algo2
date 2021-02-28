from min_pri_q import PriorityQueue

class Node:
	def __init__(self, f, l, r):
		self.freq = f
		self.left = l
		self.right = r

class Leaf(Node):
	def __init__(self, c, f):
		self.c = c
		super().__init__(f, None, None)

def huffman(C):
	n = len(C)
	q = PriorityQueue(C)

	for i in range(n-1):
		x = q.extract_min()
		y = q.extract_min()
		z = Node(x.freq + y.freq, x, y)
		q.insert(z)

	return q.extract_min()

def print_huff_codes(tree, prefix = ''):
	if type(tree) == Leaf:
		print(prefix,":",tree.c)
	else:
		print_huff_codes(tree.left, prefix + '0')
		print_huff_codes(tree.right, prefix + '1')


def main():
	C = [ Leaf('a', 45), Leaf('b', 13), Leaf('c', 12), Leaf('d', 16), Leaf('e', 9), Leaf('f', 5) ]
	print_huff_codes(huffman(C))


if __name__ == '__main__':
	main()