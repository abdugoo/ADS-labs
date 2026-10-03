def binary_search_b(a, x, n):
    left = -1
    right = n 

    while left + 1 < right:
        mid = (left+right) //2
        if a[mid] <= x:
            left = mid
        else:
            right = mid
        

    left_ind = (left + 1) if left >= 0 else 0
    if left_ind > 0:
        return left_ind
    return 0





n = int(input())
a = list(map(int, input().split()))
a.sort()
p = int(input())
sum_at_ind = []
sum = 0
for x in a:
    sum += x
    sum_at_ind.append(sum)
answer = []
for i in range(p):
    x = int(input())
    left_ind = binary_search_b(a, x, n)
    if left_ind > 0:
        answer.append(f"{left_ind} {sum_at_ind[left_ind - 1]}")
    else:
        answer.append(f"{0} {0}")
print("\n".join(answer))
