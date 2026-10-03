import sys
input = sys.stdin.readline
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

    def counter_mini_triangles(self, node):
        q = deque([node])
        count = 0
        while q:
            level_size = len(q)
            for _ in range(level_size):
                x = q.popleft()
                if x.left is not None and x.right is not None:
                    count += 1
                if x.left is not None:
                    q.append(x.left)
                if x.right is not None:
                    q.append(x.right)
        print(count)







n = int(input())
numbers = list(map(int, input().split()))
bst = BST()
bst.root = Node(numbers[0])
for x in numbers[1:]:
    bst.insert(bst.root, x)
bst.counter_mini_triangles(bst.root)