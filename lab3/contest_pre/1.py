import sys
def binary_search(a, x, n):
    left = 0
    right = n - 1
    while left <= right:
        mid = (left + right) // 2
        if a[mid] > x:
            right = mid - 1
        elif a[mid] < x:
            left = mid + 1
        else:
            return "Yes"
    return "No"


input = sys.stdin.readline
n = int(input())
numbers = list(map(int, input().split()))
x = int(input())
print(binary_search(numbers, x, n))