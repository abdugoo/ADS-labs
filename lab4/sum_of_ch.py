import sys



class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None
    def insert(self, node, data):
        if node is None:
            return Node(data)

        if data < node.data:
            node.left = self.insert(node.left, data)
        else:
            node.right= self.insert(node.right, data)

        return node

    def search(self, node, data):
        if node is None or node.data == data:
            return node

        if data < node.data:
            return self.search(node.left, data)
        else:
            return self.search(node.right, data)

    def sum_of_children(self, node):
        if node is not None:
            return node.data + self.sum_of_children(node.left) + self.sum_of_children(node.right)
        else:
            return 0
        






input = sys.stdin.readline
n = int(input())
numbers = list(map(int, input().split()))
element = int(input())

g = None
bst = BST()
for x in numbers:
    bst.root = bst.insert(bst.root, x)

node = bst.search(bst.root, element)
print(node.data)
sum = bst.sum_of_children(node)
print(sum)
