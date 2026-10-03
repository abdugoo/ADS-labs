class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


n = int(input())
a = list(map(int, input().split()))
head = None
for i in reversed(a):
    new_node = Node(i)
    new_node.next = head
    head = new_node

current = head

while current is not None and current.next is not None:
    current.next = current.next.next
    current = current.next
current = head
while current is not None:
    print(current.data, end = " ")
    current = current.next