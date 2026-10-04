import sys
input = sys.stdin.readline

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None
    def insert(self, pairs):
        stack = []
        for value, index in pairs:
            current = Node(value)
            last_popped = None
            while stack and stack[-1][1] > index:
                last_popped = stack.pop()

            if last_popped is not None:
                current.left = last_popped[0]
            if stack:
                stack[-1][0].right = current

            stack.append([current, index])

        bst.root = stack[0][0]

    def counter(self, node):
        stack = [node]
        count = 0
        while stack:
            x = stack.pop()
            if x.left is None and x.right is None:
                count += 1
                continue
            if x.right is not None:
                stack.append(x.right)
            if x.left is not None:
                stack.append(x.left)
        print(count)


bst = BST()
n = int(input())
numbers = list(map(int, input().split()))
pairs = [(value, index) for index, value in enumerate(numbers)]
pairs.sort()
bst.insert(pairs)
bst.counter(bst.root)