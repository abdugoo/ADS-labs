a, n, m = map(int, input().split())


def BinExpMod(a, n, m):
    result = 1

    while (n > 0):
        if (n % 2) == 1:
            result = ((result % m) * (a % m)) % m
        a = ((a % m) * (a % m) ) % m
        n //= 2
    return result % m

print(BinExpMod(a, n, m))