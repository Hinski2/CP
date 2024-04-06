from math import gcd
t = int(input())
for _ in range(t):
    n = int(input())
    a = 2
    while gcd(a, n - a - 1) != 1:
        a += 1
    print(a, n - a - 1, 1)