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



