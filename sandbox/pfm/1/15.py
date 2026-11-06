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

    def postorder(self, current):
        if current is None:
            return
        self.postorder(current.left)
        self.postorder(current.right)
        print(current.data, end = " ")

    def inorder(self, current):
        if current is None:
            return

        self.inorder(current.left)
        print(current.data, end = " ")
        self.inorder(current.right)

    

n = int(input())
a = list(map(int, input().split()))

bst = BST()
bst.root = Node(a[0])
for x in a[1:]:
    bst.insert(bst.root, x)

bst.postorder(bst.root)
print()
