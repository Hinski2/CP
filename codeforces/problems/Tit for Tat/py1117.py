t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = list(map(int, input().split()))
    for i in range(n - 1):
        m = min(k, v[i])
        v[i] -= m
        v[-1] += m
        k -= m
    
    print(*v, sep=' ')