import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def side(node, data, z):
    if z == 0:
        node.left = Node(data)
    else:
        node.right = Node(data)

class BST:
    def __init__(self):
        self.root = None
    def insert(self, x, y, z):
        if bst.root is None:
            bst.root = Node(x)
            side(bst.root, y, z)
        




input = sys.stdin.readline
n = int(input())
x, y, z = map(int, input().split())
bst = BST()
for i in range(n-1):
    x, y, z = map(int, input().split())

