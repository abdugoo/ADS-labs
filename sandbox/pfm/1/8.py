class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


n = int(input())
a = list(map(int, input().split()))

p, y = map(int, input().split())

head = None
for x in reversed(a):
    new_node = Node(x)
    new_node.next = head
    head = new_node


current = head
count = 0
prev = None
while current is not None and count != p:
    prev = current
    current = current.next
    count += 1

if prev is not None:
    t = prev.next
    prev.next = Node(y)
    prev.next.next = t
else:
    new_node = Node(y)
    new_node.next = head
    head = new_node

current = head
while current is not None:
    print(current.data, end = " ")
    current = current.next