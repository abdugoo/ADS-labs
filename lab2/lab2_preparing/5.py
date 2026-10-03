import math

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

n = int(input())
a = list(map(int, input().split()))
head = None
if n % 2 == 0:
    mid = n / 2
else:
    mid = math.ceil(n / 2)

count = 1
for i in reversed(a):
    if count == mid:
        count += 1
        continue
    new_node = Node(i)
    new_node.next = head
    head = new_node
    count +=1

current = head
while current is not None:
    print(current.data, end = " ")
    current = current.next
    