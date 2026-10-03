class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reversed_linked_list(head):
    prev = head
    if head is None:
        return head
    current = prev.next
    prev.next = None

    while current is not None:
        t = current.next
        current.next = prev
        prev = current 
        current = t
    
    return prev

def back(head):
    current = head
    back_e = None

    while current is not None:
        back_e = current
        current = current.next

    return back_e

def left_shift(head, x, back_e):
    if x == 0:
        return head
    front = head
    if head is None:
        return head
    current = front.next

    for _ in range(x):
        front.next = None
        back_e.next = front
        back_e = front
        front = current
        current = front.next
    
    return front

def right_shift(head, x, n):
    if x == 0:
        return head
    n = n - (1 + x)
    current = head
    for _ in range(n):
        current = current.next
    head_sec_part = current.next
    current.next = None
    ans = head_sec_part
    while ans is not None:
        t = ans 
        ans = ans.next
    t.next = head
    return head_sec_part

def app_pos(head, data, pos):
    current = head
    count = 0
    while count != (pos - 1):
        current = current.next
        count += 1
    left_side = current
    right_side = current.next
    new_node = Node(data)
    left_side.next = new_node
    new_node.next = right_side
    return head

def removing(head, pos):
    current = head
    c = pos - 1
    for _ in range(c):
        current = current.next
    
    if pos == 0:
        return current.next
    m = current.next.next
    current.next = m
    return head

def move(head, pos1, pos2):
    if pos1 == pos2:
        return head
    new_node = Node(None)
    new_node.next = head
    head = new_node
    s1 = head
    s2 = head
    for _ in range(pos1):
        s1 = s1.next
    element = s1.next
    s1.next = s1.next.next
    for _ in range(pos2):
        s2 = s2.next
    part = s2.next
    s2.next = element
    element.next = part 

    return new_node.next


head = None
n = 0
while True:
    a = list(map(int, input().split()))
    if a[0] == 0:
        break

    elif a[0] == 1: #insert
        n += 1
        data = a[1]
        pos = a[2]
        if 0 == pos:
            new_node = Node(data)
            new_node.next = head
            head = new_node
        else:
            head = app_pos(head, data, pos)

    elif a[0] == 2: #remove
        pos = a[1]
        n -= 1
        head = removing(head, pos)
    
    elif a[0] == 3: #print
        current = head
        if head is None:
            print(-1)
            continue
        
        while current is not None:
            print(current.data, end = " ")
            current = current.next
        print()
    
    elif a[0] == 4:  #replace
        p1 = a[1]
        p2 = a[2]
        head = move(head, p1, p2)
    elif a[0] == 5:   #reverse
        head = reversed_linked_list(head)
    elif a[0] == 6:   #cyclic left
        x = a[1]
        back_e = back(head)
        head = left_shift(head, x, back_e)
    elif a[0] == 7:    #cyclic right
        x = a[1]
        head = right_shift(head, x, n)
        