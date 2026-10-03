def finder_coordinates(snake, x, n, m, answers):
    left = 0
    right = n * m - 1
    while left <= right:
        mid = (left + right) // 2
        row = mid // m
        col = mid % m
        if row % 2 == 1:
            col = m - col - 1
        if snake[row][col] == x:
            answers.append(f"{row} {col}")
            return 0
        elif snake[row][col] > x:
            left = mid + 1
        else:
            right = mid - 1
    answers.append(f"{-1}")




#every column strictly decreases from top to bottom
#every even row strictly decreases from left to right
#every odd row strictly increases from left to right

t = int(input())
numbers = list(map(int, input().split()))
n, m = map(int, input().split())
snake = []
answers = []
for i in range(n):
    t = list(map(int, input().split()))
    snake.append(t)
for x in numbers:
    finder_coordinates(snake, x, n, m, answers)

print("\n".join(answers))