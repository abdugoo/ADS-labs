n = int(input())
a = list(map(int, input().split()))

current_sum = 0
best_sum = -10001
for i in a:
    current_sum += i

    if current_sum > best_sum:
        best_sum = current_sum
    if current_sum < 0:
        current_sum = 0
print(best_sum)