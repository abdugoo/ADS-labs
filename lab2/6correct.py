class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

n1, *a1 = map(int, input().split())
n2, *a2 = map(int, input().split())
head1 = None
head2 = None
for x in reversed(a1):
    new_node = Node(x)
    new_node.next = head1
    head1 = new_node
for x in reversed(a2):
    new_node = Node(x)
    new_node.next = head2
    head2 = new_node

if head1 and head2 and head1.data <= head2.data:
    head = head1
    head1 = head1.next
elif head1 and head2:
    head = head2
    head2 = head2.next

current = head
current.next = None
while head1 is not None and head2 is not None:
    if head1.data <= head2.data:
        current.next = head1
        head1 = head1.next
        current = current.next
    else:
        current.next = head2
        head2 = head2.next
        current = current.next
t = head1 if head1 is not None else head2
current.next = t
current = head
ans = []
while current is not None:
    ans.append(str(current.data))
    current = current.next
print(" ".join(ans))