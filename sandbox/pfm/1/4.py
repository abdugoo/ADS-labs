def binary_search(numbers, num):
    l = 0
    r = len(numbers) - 1
    while l < r:
        mid = (l + r) // 2
        if numbers[mid] < num:
            l = mid + 1
        else:
            r = mid
    return l + 1

n = int(input())
a = list(map(int, input().split()))
q = int(input())
x = list(map(int, input().split()))

for i in x:
    if i > a[-1]:
        print(-1)
    else:
        print(binary_search(a, i))


