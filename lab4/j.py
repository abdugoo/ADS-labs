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
        self.root = stack[0][0]
    def finder_min_by_pos(self, node, k):
        stack = []
        current = node
        count = 0
        while stack or current:
            while current:
                stack.append(current)
                current = current.left

            current = stack.pop()
            count += 1
            if count == k:
                print(current.data)
                return

            current = current.right




n, k = map(int, input().split())
if k > n:
    print(-1)
else:
    numbers = list(map(int, input().split()))
    pairs = [[value, index] for index, value in enumerate(numbers)]
    pairs.sort()
    bst = BST()
    bst.insert(pairs)
    bst.finder_min_by_pos(bst.root, k)
