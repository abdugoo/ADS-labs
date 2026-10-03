class Node:

    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
    
head = None
tail = None

while True:
    command = list(map(str, input().split()))

    if command[0] == "add_front":
        if head is None and tail is None:
            new_node = Node(command[1])
            new_node.next = head
            head = new_node
            tail = new_node
            print('ok')
            continue
        new_node = Node(command[1])
        new_node.next = head
        head.prev = new_node
        head = new_node
        print('ok')

    elif command[0] == "add_back":
        if head is None and tail is None:
            new_node = Node(command[1])
            new_node.next = head
            head = new_node
            tail = new_node
            print('ok')
            continue
        new_node = Node(command[1])
        new_node.prev = tail
        tail.next = new_node
        tail = new_node
        print('ok')

    elif command[0] == "erase_front":
        if head is None:
            print('error')
        else:
            print(head.data)
            head = head.next
            if head is None:
                tail = None
            else:
                head.prev = None
    
    elif command[0] == "erase_back":
        if tail is None:
            print('error')
        else:
            print(tail.data)
            tail = tail.prev
            if tail is None:
                head = None
            else:
                tail.next = None
    
    elif command[0] == "front":
        if head is None:
            print('error')
        else:
            print(head.data)
    elif command[0] == "back":
        if tail is None:
            print('error')
        else:
            print(tail.data)
    elif command[0] == "clear":
        head = None
        tail = None
        print('ok')
    elif command[0] == "exit":
        print("goodbye")
        break