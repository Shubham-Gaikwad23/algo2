import pytest
import random
from . import AVL

def test_avl():
	for i in range(20):
		randomlist = set(random.sample(range(1, 100), 35))
		avl = AVL.AVLTree(randomlist.pop())
		for x in randomlist:
			avl.insert(x)
		
		assert avl.is_balanced(avl.root)
