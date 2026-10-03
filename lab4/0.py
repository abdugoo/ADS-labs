class Node:
    """Узел бинарного дерева."""

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:
    """Бинарное дерево поиска."""

    def __init__(self):
        self.root = None

    # Добавление элемента
    def insert(self, node, data):
        if node is None:
            return Node(data)

        if data <= node.data:
            node.left = self.insert(node.left, data)
        else:
            node.right = self.insert(node.right, data)

        return node

    # Обход: левое поддерево → узел → правое поддерево
    def in_order(self, node):
        if node is None:
            return

        self.in_order(node.left)
        print(node.data, end=" ")
        self.in_order(node.right)

    # Обход: узел → левое поддерево → правое поддерево
    def pre_order(self, node):
        if node is None:
            return

        print(node.data, end=" ")
        self.pre_order(node.left)
        self.pre_order(node.right)

    # Обход: левое поддерево → правое поддерево → узел
    def post_order(self, node):
        if node is None:
            return

        self.post_order(node.left)
        self.post_order(node.right)
        print(node.data, end=" ")

    # Поиск минимального элемента
    def find_min(self, node):
        if node is None:
            return None

        while node.left is not None:
            node = node.left

        return node

    # Поиск максимального элемента
    def find_max(self, node):
        if node is None:
            return None

        while node.right is not None:
            node = node.right

        return node

    # Поиск значения
    def search(self, node, data):
        if node is None or node.data == data:
            return node

        if data < node.data:
            return self.search(node.left, data)
        else:
            return self.search(node.right, data)

    # Удаление одного вхождения значения
    def delete_node(self, node, data):
        if node is None:
            return None

        if data < node.data:
            node.left = self.delete_node(node.left, data)
        elif data > node.data:
            node.right = self.delete_node(node.right, data)
        else:
            # Случай 1: нет детей
            if node.left is None and node.right is None:
                return None

            # Случай 2: есть только правый ребёнок
            elif node.left is None:
                return node.right

            # Случай 3: есть только левый ребёнок
            elif node.right is None:
                return node.left

            # Случай 4: есть оба ребёнка
            else:
                predecessor = self.find_max(node.left)
                node.data = predecessor.data
                node.left = self.delete_node(
                    node.left, predecessor.data
                )

        return node

    # Высота дерева: количество узлов на самом длинном пути
    def get_height(self, node):
        if node is None:
            return 0

        return 1 + max(
            self.get_height(node.left),
            self.get_height(node.right)
        )

    # Общее количество узлов
    def count_nodes(self, node):
        if node is None:
            return 0

        return (
            1
            + self.count_nodes(node.left)
            + self.count_nodes(node.right)
        )


def main():
    bst = BST()

    values = [10, 15, 16, 13, 12, 14, 9, 8, 10, 10, 17]

    for value in values:
        bst.root = bst.insert(bst.root, value)

    print("In-order traversal (sorted): ", end="")
    bst.in_order(bst.root)
    print()

    print("Pre-order traversal: ", end="")
    bst.pre_order(bst.root)
    print()

    print("Post-order traversal: ", end="")
    bst.post_order(bst.root)
    print()

    node_min = bst.find_min(bst.root)
    node_max = bst.find_max(bst.root)

    if node_min is not None and node_max is not None:
        print(f"Min: {node_min.data}, Max: {node_max.data}")

    found = bst.search(bst.root, 13)

    if found is not None:
        print(f"Found: {found.data}")
    else:
        print("Not found")

    print(f"Tree height: {bst.get_height(bst.root)}")
    print(f"Total nodes: {bst.count_nodes(bst.root)}")

    print("Deleting node 13...")
    bst.root = bst.delete_node(bst.root, 13)

    print("In-order after deletion: ", end="")
    bst.in_order(bst.root)
    print()


if __name__ == "__main__":
    main()