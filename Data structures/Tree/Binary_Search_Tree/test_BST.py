import pytest
from BST import BST
import random


def test_preorder():
	for i in range(20):
		bst = BST()
		randomlist = random.sample(range(1, 100), 35)
		for x in randomlist:
			bst.insert(x)
		assert bst.preorder(bst.root) == bst.preorder_iterative()



def test_postorder():
	for i in range(20):
		bst = BST()
		randomlist = random.sample(range(1, 100), 35)
		for x in randomlist:
			bst.insert(x)
		assert bst.postorder(bst.root) == bst.postorder_iterative()


def test_inorder():
	for i in range(20):
		bst = BST()
		randomlist = random.sample(range(1, 100), 35)
		for x in randomlist:
			bst.insert(x)
		assert bst.inorder(bst.root) == bst.inorder_iterative()
