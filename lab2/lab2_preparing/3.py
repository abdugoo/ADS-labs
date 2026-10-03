stack = []
n = int(input())
for i in range(n):
    name = input()
    if stack:
        if stack[-1] == name:
            continue
        else:
            stack.append(name)
    else:
        stack.append(name)
print(len(stack))
for i in stack:
    print(i)