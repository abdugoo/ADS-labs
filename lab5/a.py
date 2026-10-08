import sys
input = sys.stdin.readline




class MinHeap:
    def __init__(self):
        pass

    def heapify(self, i):
        while True:
            smallest = i
            left = i * 2 + 1
            right = i * 2 + 2
            n = len(numbers)
            if left < n and numbers[left] < numbers[smallest]:
                smallest = left

            if right < n and numbers[right] < numbers[smallest]:
                smallest = right

            if smallest == i:
                break

            numbers[smallest], numbers[i] = numbers[i], numbers[smallest]
            i = smallest
    
    def insert(self, element):
        numbers.append(element)

        index = len(numbers) - 1
        parent = (index - 1) // 2
        
        while index > 0 and numbers[index] < numbers[parent]:
            numbers[index], numbers[parent] = numbers[parent], numbers[index]
            index = parent
            parent = (index - 1) // 2

    def ExctractMini(self):
        mini = numbers[0]
        numbers[0] = numbers[-1]
        numbers.pop()
        if len(numbers) > 0:
            self.heapify(0)

        return mini

n = int(input())
numbers = list(map(int, input().split()))
mheap = MinHeap()
sum = 0
for i in range((len(numbers)//2 - 1), -1, -1):
    mheap.heapify(i)
while len(numbers) > 1:
    x1 = mheap.ExctractMini()
    x2 =  numbers[0]
    s = x1 + x2
    sum += s

    numbers[0] = s
    mheap.heapify(0)
    """
    x1 = mheap.ExctractMini()
    x2 = mheap.ExctractMini()
    s = x1 + x2
    mheap.insert(s)
    sum += s
    """

print(sum)
    

