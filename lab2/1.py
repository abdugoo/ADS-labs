from collections import deque

n = int(input())

def cheker(t):
    letters = input().split()
    frequency = {}
    queue = deque()
    answers = []        # a a a b b c d e e
    for i in letters:
        if not frequency.get(i):
            frequency[i] = 1
            queue.append(i)
        else:
            frequency[i] += 1
            while queue and frequency[queue[0]] > 1:
                queue.popleft()

            

        if queue:
            answers.append(queue[0])
        else:
            answers.append(-1)
    for i in answers:
        print(i, end = " ")
    print()
        
for i in range(n):
    t = int(input())
    cheker(t)
