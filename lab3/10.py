
def tester(a, mid, k):
    sheep = 0
    for row in a:
        x1, y1, x2, y2 = row
        if x2 <= mid and y2 <= mid:
            sheep += 1
    return sheep >= k




def minimum_length(a, k, max_value):
    left = 0
    right = max_value
    while left + 1 < right:
        mid = (left + right) // 2
        if tester(a, mid, k):
            right = mid
        else:
            left = mid
    print(right)




n, k = map(int, input().split())
a = []
for i in range(n):
    t = list(map(int, input().split()))   #x1 y1 x2 y2
    a.append(t)

max_value = max(max(row) for row in a)
minimum_length(a, k, max_value)