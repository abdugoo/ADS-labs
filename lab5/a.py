import sys
input = sys.stdin.readline




class MinHeap:
    def __init__(self):
        self.a = [] #list 

    def parent(self, ind):
        return (ind - 1) // 2
    def left(self, ind):
        return (ind * 2 + 1)   
    def right(self, ind):
        return (ind * 2 + 2)
    def GetMin(self):
        return self.a[0]

    def insert(self, x):
        self.a.append(x)

        index = len(self.a) - 1
        while index > 0 and self.a[self.parent(index)] > self.a[index]:
            self.a[self.parent(index)], self.a[index] = self.a[index], self.a[self.parent(index)]
            index = self.parent(index)

    def heapify(self, i):
        j = self.left(i)
        if self.left(i) > (len(self.a) - 1):
            return #if index out of list we stop the recursion
        
        if self.right(i) < len(self.a) and self.a[self.right(i)] < self.a[j]:
            j = self.right(i)

        if self.a[i] > self.a[j]:
            self.a[i], self.a[j] = self.a[j], self.a[i]
            self.heapify(j)

    def ExctractMini(self):
        mini = self.a[0]
        self.a[0] = self.a[len(self.a) - 1]
        self.a.pop()
        if len(self.a) > 0:
            self.heapify(0)

        return mini

n = int(input())
numbers = list(map(int, input().split()))
mheap = MinHeap()
for x in numbers:
    mheap.insert(x)

nn = n // 2 + 1

sum = 0
print(mheap.a)
while len(mheap.a) > 1:
    x1 = mheap.ExctractMini()
    x2 = mheap.ExctractMini()
    s = x1 + x2
    mheap.insert(s)
    sum += s


print(sum)
    

