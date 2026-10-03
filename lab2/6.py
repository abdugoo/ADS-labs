from collections import deque

a = deque(map(int, input().split()))
b = deque(map(int, input().split()))

n1 = a.popleft()
n2 = b.popleft()

sorted_list = []

while len(a) > 0 and len(b) > 0:
    if a[0] > b[0]:
        sorted_list.append(b[0])
        b.popleft()
    elif a[0] == b[0]:
        sorted_list.append(a[0])
        sorted_list.append(a[0])
        a.popleft()
        b.popleft()
    else:
        sorted_list.append(a[0])
        a.popleft()

if a:
    sorted_list.extend(a)
if b:
    sorted_list.extend(b)

for i in sorted_list:
    print(i, end = " ")