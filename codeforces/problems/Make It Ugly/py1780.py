t = int(input())
for _ in range(t):
    n = int(input())
    vs = [int(i) for i in input().split()]
    
    if all([i == vs[0] for i in vs]) or len(vs) <= 2:
        print(-1)
        continue
    
    ans, x = n, -1
    for i in range(n):
        if vs[i] != vs[0]:
            ans = min(ans, i - x - 1)
            x = i 
    ans = min(ans, n - x - 1)
    if ans == n:
        print(-1)
    else:
        print(ans)
        