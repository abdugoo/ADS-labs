def cc(a, x, k):
    count = 0
    for i in a:
        count += (i // x)
    return count >= k


def mlor(n, k, a):
    left = 0
    right = max(a)
    for _ in range(100):
        mid = (left + right) / 2

        if cc(a, mid, k):
            left = mid
        else:
            right = mid
    return left


n, k = map(int, input().split())
a = list(map(int, input().split()))
answer = mlor(n, k, a)
print(f"{answer:.9f}")