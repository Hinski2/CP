t = int(input())
for _ in range(t):
    n = int(input())
    v = [i for i in range(1, n + 1)]
    
    print(n)
    print(*v)
    for i in range(n - 1):
        v[i], v[i + 1] = v[i + 1], v[i]
        print(*v)
        