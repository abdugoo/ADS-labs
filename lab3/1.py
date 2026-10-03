def binary_search(a, x):
    l = 0
    r = len(a) - 1

    while l <= r:
        mid = (l + r) // 2

        if a[mid] < x:
            l = mid + 1
        elif a[mid] > x:
            r = mid - 1
        else:
            return 'Yes'
    return 'No'




n = int(input())
a = list(map(int, input().split()))
x = int(input())
print()