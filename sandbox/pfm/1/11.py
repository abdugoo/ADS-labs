class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(sefl):
        sefl.root = None

    def insert(self, current, data):
        prev = None
        while current is not None:
            prev = current
            if data <= current.data:
                current = current.left
            else:
                current = current.right
        if data <= prev.data:
            prev.left = Node(data)
        else:
            prev.right = Node(data)

    def count_leaves1(self, current, count):
        if current is None:
            return

        if current.left is None and current.right is None:
            count[0] += 1

        self.count_leaves1(current.left, count)
        self.count_leaves1(current.right, count)

    def count_leaves2(self, current):
        if current is None:
            return 0

        if current.left is None and current.right is None:
            return 1

        return (
            self.count_leaves2(current.left) + self.count_leaves2(current.right)
        )

        




n = int(input())
a = list(map(int, input().split()))
bst = BST()
bst.root = Node(a[0])
for i in a[1:]:
    bst.insert(bst.root, i)

current = bst.root
count = [0]
bst.count_leaves1(current, count)
print(count[0])

print(bst.count_leaves2(current))
