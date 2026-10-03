def binary_search(p, x, n):
    left = 0
    right = n - 1
    while left <= right:
        mid = (left + right) //2
        if p[mid] >= x:
            right = mid - 1
        else:
            left = mid + 1
    print(left + 1)


n, m = map(int, input().split())
a = list(map(int, input().split()))
p = []
end_s = 0
for x in a:
    end_s += x
    p.append(end_s)

for i in range(m):
    b = int(input())
    binary_search(p, b, n)