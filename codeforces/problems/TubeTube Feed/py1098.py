q = int(input())
for _ in range(q):
    n, t = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    v = [a[i] + i <= t for i in range(n)]
    maks, idx = -1, -1
    for i in range(n):
        if v[i] and maks < b[i]:
            maks = b[i]
            idx = i + 1
    
    print(idx)