import sys
from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

input = sys.stdin.readline
n = int(input())

nodes = [None] + [Node(i) for i in range(1,n + 1)]
for _ in range(n - 1):
    x, y, z = map(int, input().split())
    if z == 0:
        nodes[x].left = nodes[y]
    else:
        nodes[x].right = nodes[y]

q = deque([nodes[1]])
ans = 0
while q:
    level_size = len(q)
    ans = max(ans, level_size)
    for _ in range(level_size):
        x = q.popleft()
        if x.right is not None:
            q.append(x.right)
        if x.left is not None:
            q.append(x.left)


print(ans)