def policz(l):
    n = len(l)
    o = (l[::2])[::-1]
    e = [i for i in range(6, n + 1, 2)]
    l = o + [4, 2] + e
    print(*l)


t = int(input())
for _ in range(t):
    n = int(input())
    if n == 2 or n == 3: print(-1)
    elif n == 4: print(*[3, 1, 4, 2])
    else: policz([i for i in range(1, n + 1)])