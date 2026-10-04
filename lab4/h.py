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

    def insert(self, node, data):
        if node is None:
            return Node(data)

        if data <= node.data:
            node.left = self.insert(node.left, data)
        else:
            node.right = self.insert(node.right, data)

        return node
        

    def reversed_in_order(self, node, ans, s):
        if node.right is not None:
            self.reversed_in_order(node.right, ans, s)

        s[0] = node.data + s[0]
        node.data = s[0]
        ans.append(node.data)

        if node.left is not None:
            self.reversed_in_order(node.left, ans, s)






n = int(input())
numbers = list(map(int, input().split()))
bst = BST()
ans = []
for x in numbers:
    bst.root = bst.insert(bst.root, x)

s = [0]
bst.reversed_in_order(bst.root, ans, s)
print(*ans)