# some formulas and concepts
## formulas
1) The maximum number of nodes at level ‘l’ of a binary tree is pow(2, l-1).
    Here level is number of nodes on path from root to the node (including root and node). Level of root is 1.
2) Maximum number of nodes in a binary tree of height ‘h’ is pow(2, h) - 1.
3) In a Binary Tree with N nodes, minimum possible height or minimum number of levels is  ? Log2(N+1) ? Log2(N+1) ? – 1
4) A Binary Tree with L leaves has at least   ? Log2L ? + 1   levels
    L   <=  pow(2, l-1)  [From Point 1]
    l =   ? Log2L ? + 1
    where l is the minimum number of levels.
5) In Binary tree where every node has 0 or 2 children, number of leaf nodes is always one more than nodes with two children.
    L = T + 1, Where L = Number of leaf nodes
    T = Number of internal nodes with two children

## Full Binary Tree
    A Binary Tree is full if every node has 0 or 2 children. Following are examples of a
    full binary tree. We can also say a full binary tree is a binary tree in which all
    nodes except leaves have two children.
                   18
           /       \
         15         30
        /  \        /  \
      40    50    100   40

             18
           /    \
         15     20
        /  \
      40    50
    /   \
   30   50

               18
            /     \
          40       30
                   /  \
                 100   40

## Complete Binary Tree
    A Binary Tree is complete Binary Tree if all levels are completely filled except
    possibly the last level and the last level has all keys as left as possible
    Following are examples of Complete Binary Trees
               18
           /       \
         15         30
        /  \        /  \
      40    50    100   40


               18
           /       \
         15         30
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9

## Perfect Binary Tree
    A Binary tree is Perfect Binary Tree in which all internal nodes have two children and
    all leaves are at the same level.
    Following are examples of Perfect Binary Trees.
               18
           /       \
         15         30
        /  \        /  \
      40    50    100   40


               18
           /       \
         15         30

## Balanced Binary Tree
    A binary tree is balanced if the height of the tree is O(Log n) where n is the number
    of nodes. For Example, AVL tree maintains O(Log n) height by making sure that the
    difference between heights of left and right subtrees is 1. Red-Black trees maintain
    O(Log n) height by making sure that the number of Black nodes on every root to leaf
    paths are same and there are no adjacent red nodes. Balanced Binary Search trees are
    performance wise good as they provide O(log n) time for search, insert and delete.

## A degenerate (or pathological) tree
     A Tree where every internal node has one child. Such trees are performance-wise same
     as linked list.
          10
          /
        20
         \
         30
          \
          40
