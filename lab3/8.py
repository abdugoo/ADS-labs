n, k = map(int, input().split())
a = list(map(int, input().split()))

left = 0
sum = 0
best = float('inf')
for right in range(n):
    sum += a[right]

    while sum >= k and left <= right:
        t = right - left + 1
        if t < best:
            best = t
        sum -= a[left]
        left += 1
print(best)