"""
Tower of Hanoi, is a mathematical puzzle which consists of three towers (pegs) 
and more than one rings is as depicted

The mission is to move all the disks to some another tower without violating 
the sequence of arrangement. A few rules to be followed for Tower of Hanoi are

    Only one disk can be moved among the towers at any given time.
    Only the "top" disk can be removed.
    No large disk can sit over a small disk.
    
In this case, move all disks from x to z
"""

def move(n, a, b):
    print 'move %d, %s -> %s' %(n, a, b)

# recursive fucntion
def hanoi(n, x, y, z):
    if 1 == n:
        move(n, x, z)
        return   # this is immprotant since it's the exist of recursive
    hanoi(n-1, x, z, y) # regard n-1 disks as a unit, move it from x to y
    move(n, x, z)       # move the biggest disk n from x to z
    hanoi(n-1, y, x, z) # move n-1 disks unit from y to z, complete

hanoi(3, 'x', 'y', 'z')
"""
result:
move 1, x -> z
move 2, x -> y
move 1, z -> y
move 3, x -> z
move 1, y -> x
move 2, y -> z
move 1, x -> z
"""

