a, b = map(int, input().split())


def m_gcd(a, b):
    t = -1
    while t != 0:
        t = a % b
        a = b
        b = t
    print(a)


m_gcd(a, b)