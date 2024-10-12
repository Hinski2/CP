t = int(input())
for _ in range(t):
    n = int(input())
    v = [i + 1 for i in range(n)]
    for i in range(1 if n % 2 else 0, n, 2):
        v[i], v[i + 1] = v[i + 1], v[i]
    print(*v) 
    
    