n = int(input())

class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

a = list(map(int, input().split()))
head = None
for i in reversed(a):
    new_node = Node(i)
    new_node.next = head
    head = new_node

t = None
prev = head
current = prev.next
prev.next = None
for i in range(n):
    if current is not None:
        t = current.next
        current.next = prev
        prev = current
        current = t

head = prev
current = head

while current is not None:
    print(current.data, end = " ")
    current = current.next