class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

n = int(input())
a = list(map(int, input().split()))

current_sum = 0
best_sum = float("-inf")

head = None
for i in reversed(a):
    new_node = Node(i)
    new_node.next = head
    head = new_node

current_node = head
while current_node is not None:
    current_sum += current_node.data

    if current_sum > best_sum:
        best_sum = current_sum
    if current_sum < 0:
        current_sum = 0
    current_node = current_node.next
print(best_sum)