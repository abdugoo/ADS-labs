class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


n = int(input())
a = list(map(int, input().split()))

head = None
for x in reversed(a):
    new_node = Node(x)
    new_node.next = head
    head = new_node

current = head
prev = None
while current is not None:
    head = current
    t = current.next
    current.next = prev
    prev = current
    current = t

current = head
while current is not None:
    print(current.data, end =" ")
    current = current.next
