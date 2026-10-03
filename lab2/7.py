class Node:
    def __init__(self, data):
        self.data = data
        self.next = None




n, t = map(int, input().split())
a = input().split()
head = None
for x in reversed(a):
    new_node = Node(x)
    new_node.next = head
    head = new_node


current = head
t -= 1
for i in range(t):
    current = current.next

new_head = current.next
current.next = None

cur = new_head
while cur.next is not None:
    cur = cur.next
cur.next = head

while new_head is not None:
    print(new_head.data, end= " ")
    new_head = new_head.next

