# code snaps from https://www.geeksforgeeks.org/binary-tree-data-structure/#Introduction
from __future__ import print_function

def print_satrt(start):
    print("\n============%s test start============" % start.__name__)

def print_end(end):
    print("============%s test end============\n" % end.__name__)

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
        self.nums.append(temp.val)
        #print("address is %d, val is %d" % (id(temp), temp.val))
        self._inorder_inner(temp.right)

    """function to insert element in binary tree """
    def insert(self, val):
        q = []
        q.append(self)
        while (len(q)):
            self = q.pop(0)
            if not self.left:
                self.left = Node(val)
                break
            else:
                q.append(self.left)
            if not self.right:
                self.right = Node(val)
                break
            else:
                q.append(self.right)

    #    Algorithm
    #    1. Starting at root, find the deepest and rightmost node in binary tree and node
    #       which we want to delete.
    #    2. Replace the deepest rightmost node's data with node to be deleted
    #    3. Then delete the deepest rightmost node.
    def delete(self, val):
        child_to_parent_dic = {}
        q = [self]
        while len(q):
            tmp = q.pop(0)
            if tmp.val == val:
                key_node = tmp
            if tmp.left:
                q.append(tmp.left)
                child_to_parent_dic[tmp.left] = ['left', tmp]
            if tmp.right:
                q.append(tmp.right)
                child_to_parent_dic[tmp.right] = ['right', tmp]
        key_node.val = tmp.val
        if child_to_parent_dic.has_key(tmp):
            result = child_to_parent_dic[tmp]
            if 'left' == result[0]:
                #print(" result[1] address is %d, result[1] address.left is %d, on the left:%d" % (id(result[1]), id(result[1].left), result[1].left.val))
                result[1].left = None
            else:
                #print(" result[1] address is %d, result[1] address.right is %d, on the right:%d" % (id(result[1]), id(result[1].right), result[1].right.val))
                result[1].right = None

            return self.inorder()
        else:
            #print("Not correct!")
            return []

    def _delete_node(self, tar_node):
        pass

def test_create_tree():
    print_satrt(test_create_tree)
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)

    assert 1 == root.val
    assert 2 == root.left.val
    assert 3 == root.right.val
    assert 4 == root.left.left.val
    print_end(test_create_tree)

def test_insert_tree():
    print_satrt(test_insert_tree)

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

#                       insert 12
#
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
    print_end(test_insert_tree)

def test_delete_tree():
    print_satrt(test_delete_tree)
#                       delete 11
#
#             10           ===>         10
#           /    \         ===>      /      \
#          11     9        ===>     8        9
#         /  \    /  \     ===>    /  \      /
#        7    12 15   8    ===>   7    12   15
    root = Node(10)
    root.left = Node(11)
    root.left.left = Node(7)
    root.left.right = Node(12)
    root.right = Node(9)
    root.right.left = Node(15)
    root.right.right = Node(8)
    assert[7, 11, 12, 10, 15, 9, 8] == root.inorder()
    assert[7, 8, 12, 10, 15, 9] == root.delete(11)
    print_end(test_delete_tree)



















