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



        


    def post_order(self, node_root):
        stack = [[node_root, False]]
        height = {}
        max_diameter = 0
        while stack:
            if stack[-1][1]:
                x, visited = stack.pop()
                left_h = height.get(x.left, 0)
                right_h = height.get(x.right, 0)
                height[x] = 1 + max(left_h, right_h)
                current_diameter = left_h + right_h + 1
                max_diameter = max(max_diameter, current_diameter)

                if stack and (stack[-1][0].right == x or (stack[-1][0].left == x and stack[-1][0].right is None)):
                    stack[-1][1] = True
            else:
                x = stack[-1][0]
                if x.right is not None:
                    stack.append([x.right, False])
                if x.left is not None:
                    stack.append([x.left, False])
                if x.left is None and x.right is None:
                    stack[-1][1] = True

        print(max_diameter)
                

    


n = int(input())
numbers= list(map(int, input().split()))
numbers = list(dict.fromkeys(numbers))
pairs = [(value, i) for i, value in enumerate(numbers)]
pairs.sort()
bst = BST()
bst.insert(pairs)

bst.post_order(bst.root)