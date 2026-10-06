

class MinHeap:
    def __init__(self):
        self.a = []
        

    def parent(self, i):
        return (i - 1) // 2

    def left(self, i):
        return i * 2 + 1

    def right(self, i):
        return i * 2 + 2

    def GetMin(self, a):
        return self.a[0]



    
