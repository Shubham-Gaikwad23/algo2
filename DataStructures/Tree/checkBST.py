# https://practice.geeksforgeeks.org/problems/check-for-bst/1

from Binary_Search_Tree.BST import BST

def check_bst(bst):
    if bst.root:
        stk = [bst.root]
    else:
        stk = []

    while stk:
        cur = stk.pop()
        left = cur.left
        right = cur.right

        if left:
            if left.key > cur.key:
                return False
            stk.append(left)

        if right:
            if right.key < cur.key:
                return False
            stk.append(right)

    return True





def main():
    bst = BST()
    bst.root = bst.Node(10)
    bst.root.left = bst.Node(100)
    print(check_bst(bst))


if __name__ == '__main__':
    main()





































































# class Node:
#     def __init__(self, val):
#         self.right = None
#         self.data = val
#         self.left = None


# # return True if the given tree is a BST, else return False
# def isBST(root):
#     import math
#     global prev, ordered
#     ordered = True
#     prev = -math.inf
#     inorder(root)
#     return ordered

# def inorder(root):
#     global prev, ordered
#     if root:
#         inorder(root.left)
#         if prev >= root.data:
#             ordered = False
#         prev = root.data
#         inorder(root.right