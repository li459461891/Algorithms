# code snaps from https://www.geeksforgeeks.org/binary-tree-data-structure/#Introduction
from __future__ import print_function

class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val
        self.nums = []

    def inorder(self):
        self.nums = []
        self._inorder_inner(self)
        return self.nums

    def _inorder_inner(self, temp):
        if not temp:
            return
        self._inorder_inner(temp.left)
        # print(temp.val, end=" ")
        self.nums.append(temp.val)
        self._inorder_inner(temp.right)

    """function to insert element in binary tree """
    def insert(self, val):
        self.nums = []
        self.nums.append(self)
        while (len(self.nums)):
            self = self.nums.pop(0)
            if not self.left:
                self.left = Node(val)
                break
            else:
                self.nums.append(self.left)
            if not self.right:
                self.right = Node(val)
                break
            else:
                self.nums.append(self.right)

def test_create_tree():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)

    assert 1 == root.val
    assert 2 == root.left.val
    assert 3 == root.right.val
    assert 4 == root.left.left.val

def test_insert_tree():

#            1           ===>             1
#           /  \         ===>            /  \
#          2    3        ===>           2    3
#                                      /
#                                     4
    root1 = Node(1)
    root1.left = Node(2)
    root1.right = Node(3)
    assert [2, 1, 3] == root1.inorder()
    root1.insert(4)
    assert [4, 2, 1, 3] == root1.inorder()

#            10          ===>          10
#           /   \        ===>       /      \
#          11    9       ===>     11        9
#         /     /  \     ===>    /  \      /  \
#        7     15   8    ===>   7    12   15   8
    root2 = Node(10)
    root2.left = Node(11)
    root2.left.left = Node(7)
    root2.right = Node(9)
    root2.right.left = Node(15)
    root2.right.right = Node(8)

    assert [7, 11, 10, 15, 9, 8] == root2.inorder()
    root2.insert(12)
    assert [7, 11, 12, 10, 15, 9, 8] == root2.inorder()





















