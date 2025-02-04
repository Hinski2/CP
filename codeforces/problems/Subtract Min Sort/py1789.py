t = int(input())
for _ in range(t):
    n = int(input())
    vs = [int(u) for u in input().split()]
    for i in range(n - 1):
        m = min(vs[i], vs[i + 1])
        vs[i] -= m; vs[i + 1] -= m
    
    if all(u <= w for u, w in zip(vs[0:], vs[1:])):
        print("YES")
    else:
        print("NO")
        