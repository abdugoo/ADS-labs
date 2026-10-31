def binary_search(a, target):
    l = 0
    r = len(a) - 1
    while l <= r:
        mid = (l + r) // 2
        if a[mid] == target:
            return mid
        elif a[mid] > target:
            r = mid -1
        else:
            l = mid + 1



n = int(input())
a = list(map(int, input().split()))
target = int(input())
if binary_search(a, target) is not None:
    print("Yes")
else:
    print("No")