import sys

def bslb(a, x, n):
    l = -1
    r = n
    while l + 1 < r:
        mid = (l + r) // 2
        if x <= a[mid]:
            r = mid
        else:
            l = mid
    return r

def bsrb(a, x, n):
    l = -1
    r = n
    while l + 1 < r:
        mid = (l + r) // 2
        if a[mid] > x:
            r = mid
        else:
            l = mid

    return r



def cheker_for_boundry(a, l1, r1, l2 , r2, n):
    sum = 0
    if l2 <= r1 and l1 <= r2:
        li = bslb(a, min(l1, l2), n)
        ri = bsrb(a, max(r1, r2), n)
        print(ri - li)
    else:
        sum = (bsrb(a, r1, n) - bslb(a, l1, n)) + (bsrb(a, r2, n) - bslb(a, l2, n))
        print(sum)




input = sys.stdin.readline
n, q = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()
for _ in range(q):
    l1, r1, l2, r2 = map(int, input().split())
    cheker_for_boundry(numbers, l1, r1, l2, r2, n)