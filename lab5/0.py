import sys
input = sys.stdin.readline

class MinHeap:
    def __init__(self):
        self.a = []
        

    def parent(self, i):
        return (i - 1) // 2

    def left(self, i):
        return i * 2 + 1

    def right(self, i):
        return i * 2 + 2

    def GetMin(self):
        return self.a[0]

    def insert(self, element):
        self.a.append(element)

        index = len(self.a) - 1
        while index > 0 and self.a[index] < self.a[self.parent(index)]:
            self.a[index], self.a[self.parent(index)] = self.a[self.parent(index)], self.a[index]
            index = self.parent(index)

    def heapify(self, i):
        j = mh.left(i)
        if self.left(i) > (len(self.a) - 1):
            return

        if self.right(i) < len(self.a) and self.a[self.right(i)] < self.a[self.left(i)]:
            j = self.right(i)

        if self.a[i] > self.a[j]:
            self.a[i], self.a[j] = self.a[j], self.a[i]
            self.heapify(j)

    def ExtractMini(self):
        mini = self.a[0]
        self.a[0] = self.a[len(self.a) - 1]
        self.a.pop()

        if len(self.a) > 0:
            self.heapify(0)

        return mini



n = int(input())
numbers = list(map(int, input().split()))
mh = MinHeap()
for i in numbers:
    mh.insert(i)

print(mh.a)
print(mh.ExtractMini())
print(mh.a)
    
