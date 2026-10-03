import sys
from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, current, data):
        prev = None
        while current is not None:
            prev = current
            if data < current.data:
                current = current.left
            else:
                current = current.right

        if data < prev.data:
            prev.left = Node(data)
        else:
            prev.right = Node(data)

    def search(self, current, data):
        if current is not None and current.data == data:
            return current

        while current is not None:
            if data == current.data:
                return current
            elif data < current.data:
                current = current.left
            else:
                current = current.right


    def pre_order(self, node):
        stack = [node]
        if node is None:
            return 

        while stack:
            node = stack.pop()
            print(node.data, end =" ")

            if node.right is not None:
                stack.append(node.right)
            if node.left is not None:
                stack.append(node.left)


inpurt = sys.stdin.readline
n = int(input())
numbers = list(map(int, input().split()))
bst = BST()
bst.root = Node(numbers[0])
k = int(input())
for x in numbers[1:]:
    bst.insert(bst.root, x)


p = bst.search(bst.root, k)
bst.pre_order(p)