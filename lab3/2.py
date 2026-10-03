def binary_search_left_boundry(a, x, n):
    left = -1
    right = n

    while left + 1 < right:
        mid = (left + right) // 2
        if a[mid] >= x:
            right = mid
        else:
            left = mid

    return right

def binary_search_right_boundry(a, x, n):
    left = -1
    right = n

    while left + 1 < right:
        mid = (left + right) // 2
        if a[mid] > x:
            right = mid
        else:
            left = mid

    return right


def cheker_for_boundry(a, l1, r1, l2, r2, n):
    sum = 0
    if l2 <= r1 and l1 <= r2:
        left_ind = binary_search_left_boundry(a, min(l1, l2), n)
        right_ind = binary_search_right_boundry(a, max(r1, r2), n)
        print((right_ind - left_ind))
    else:
        left_ind1 = binary_search_left_boundry(a, l1, n)
        right_ind1 = binary_search_right_boundry(a, r1, n)
        left_ind2 = binary_search_left_boundry(a, l2, n)
        right_ind2 = binary_search_right_boundry(a, r2, n)
        sum += (right_ind1 - left_ind1)
        sum += (right_ind2 - left_ind2)
        print(sum)


n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
for i in range(q):
    l1, r1, l2, r2 = map(int, input().split())
    cheker_for_boundry(a, l1, r1, l2, r2, n)

