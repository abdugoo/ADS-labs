from collections import deque

def cheker(t):
    letters = input().split()
    frequency = {}
    queue = deque()
    answers = []

    for x in letters:
        if not frequency.get(x):
            frequency[x] = 1
            queue.append(x)
        else:
            frequency[x] += 1
            while queue and frequency[queue[0]] > 1:
                queue.popleft()

        if queue:
            answers.append(queue[0])
        else:
            answers.append(-1)

    for x in answers:
        print(x, end = " ")
    print()



n = int(input())
for _ in range(n):
    t = int(input())
    cheker(t)