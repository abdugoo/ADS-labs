def cheker(a, psum, k):
    blocks = 1
    current_sum = 0
    for x in a:
        current_sum += x
        if current_sum > psum:
            current_sum = 0
            current_sum += x
            blocks += 1
    return blocks <= k
        
def minimum_possible_max(a, k):
    left = max(a) - 1
    right = sum(a)
    while left + 1 < right:
        mid = (left + right) // 2
        if cheker(a, mid, k):
            right = mid
        else:
            left = mid
    print(right)

n, k = map(int, input().split())
a = list(map(int, input().split()))
minimum_possible_max(a, k)


# 1 2 3 4 5 6 7 8 9 10 11 12 13 14
# f f f f t t t t t t  t  t  t  t
