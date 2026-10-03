class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

n = int(input())
a = list(map(int, input().split()))
head = None
for x in a:
    new_node = Node(x)
    new_node.next = head
    head = new_node


t = None
prev = head
current = prev.next
prev.next = None
while current is not None:
    t = current.next
    current.next = prev
    prev = current
    current = t

head = prev
current = head