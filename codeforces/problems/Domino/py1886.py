n = int(input())
l, u = [], []
for _ in range(n):
    a, b = map(int, input().split())
    l.append(a)
    u.append(b)

if sum(l) % 2 or sum(u) % 2:
    ok = False
    for i in range(n):
        if l[i] % 2 != u[i] % 2:
            ok = True
    if ok and sum(l) % 2 and sum(u) % 2: 
        print(1)
    else:
        print(-1) 
else:
    print(0) 

