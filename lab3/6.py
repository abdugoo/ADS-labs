def count_hours(a, x):
    sum = 0
    for t in a:
        sum += (t + x - 1) // x
    return sum


def min_golden_bars(a, h, maxx):
    left = 0
    right = maxx
    while left + 1 < right:
        mid = (left + right) // 2
        hours = count_hours(a, mid)
        if hours <= h:
            right = mid
        else:
            left = mid
    print(right)


n, h = map(int, input().split())
a = list(map(int, input().split()))
maxx = max(a)
min_golden_bars(a, h, maxx)
