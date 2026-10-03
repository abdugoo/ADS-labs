import math

class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

n = int(input())
numbers = list(map(int, input().split()))
head = None

if n % 2 == 0:
    n = (n / 2)
else:
    n = math.ceil(n/2)

count = 1
for i in reversed(numbers):
    if count == n:
        count += 1
        continue
        
    new_node = Node(i)
    new_node.next = head
    head = new_node
    count += 1

current = head
while current is not None:
    print(current.data, end = " ")
    current = current.next



