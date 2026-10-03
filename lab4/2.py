import sys



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
            if data <= prev.data:
                current = current.left
            else:
                current = current.right

        if data <= prev.data:
            prev.left = Node(data)
        else:
            prev.right = Node(data)

    def search(self, node, data):
        if node is None or node.data == data:
            return node

        if data < node.data:
            return self.search(node.left, data)
        else:
            return self.search(node.right, data)

    def count_children(self, node):
        if node is None:
            return 0
        stack = [node]
        count = 1
        while stack:
            current = stack.pop()

            if current.left is not None:
                count += 1
                stack.append(current.left)
            if current.right is not None:
                count += 1
                stack.append(current.right)
        return count






input = sys.stdin.readline
n = int(input())
numbers = list(map(int, input().split()))
element = int(input())

g = None
bst = BST()
bst.root = Node(numbers[0])
for x in numbers[1:]:
    current = bst.root
    bst.insert(current, x)

node = bst.search(bst.root, element)
count = bst.count_children(node)

print(count)
