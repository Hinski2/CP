t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    
    s = set()
    for i in range(n):
        for j in range(n):
            if i == j: continue
            s.add(abs(v[i] - v[j]))
    print(len(s))