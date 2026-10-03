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
            if data < current.data:
                current = current.left
            else:
                current = current.right
        if data <= prev.data:
            prev.left = Node(data)
        else:
            prev.right = Node(data)

    def counter_summer(self, node):
        ans = []
        line = [node]
        count = 0
        while line:
            sum = 0
            count += 1
            t = []
            for x in line:
                if x.left is not None:
                    t.append(x.left)
                if x.right is not None:
                    t.append(x.right)
                sum += x.data
            line = t
            ans.append(sum)
        return count, ans


input = sys.stdin.readline
n = int(input())
numbers = list(map(int, input().split()))
bst = BST()
bst.root = Node(numbers[0])
for x in numbers[1:]:
    bst.insert(bst.root, x)

count, ans = bst.counter_summer(bst.root)
print(count)
print(" ".join(map(str, ans)))