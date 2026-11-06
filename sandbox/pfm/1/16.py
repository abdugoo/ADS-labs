class Node:
    def __init__(self, data):
        self.data= data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, current, data):
        prev = current
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

    def preorder(self, current):
        stack = [current]
        while stack:
            current = stack.pop()
            print(current.data, end=" ")

            if current.right is not None:
                stack.append(current.right)
            if current.left is not None:
                stack.append(current.left)

    def postorder(self, current):
        stack = [current]
        ans = []
        while stack:
            current = stack.pop()
            ans.append(current.data)

            if current.left is not None:
                stack.append(current.left)
            if current.right is not None:
                stack.append(current.right)

        print(*ans[::-1])

    def inorder(self, current):
        stack = []
        while current is not None or stack:
            while current is not None:
                stack.append(current)
                current = current.left

            current = stack.pop()
            print(current.data, end =" ")
            current = current.right