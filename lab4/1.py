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


    def in_order(self, node):
        if node is None:
            return 
        self.in_order(node.left)
        print(node.data, end = " ")
        self.in_order(node.right)

def tester_path(root, path, ans):
    current = root
    for x in path:
        if x == "R":
            current = current.right
        else:
            current = current.left
        if current is None:
            ans.append("NO")
            return
    ans.append("YES")


input = sys.stdin.readline
n, m = map(int, input().split())
numbers = list(map(int, input().split()))
bst = BST()

bst.root = Node(numbers[0])
for i in numbers[1:]:
    current = bst.root
    bst.insert(current, i)
ans = []
for _ in range(m):
    path = input().strip()
    tester_path(bst.root, path, ans)
print("\n".join(ans))