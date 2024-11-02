t = int(input())
for _ in range(t):
    n = int(input())
    v = [[int(x) for x in input().split()] for _ in range(n)]
    ans = 0
    for i in range(n):
        for j in range(n):
            if v[i][j] >= 0: continue
            ile, a, b = 0, i, j
            while a < n and b < n:
                ile = min(ile, v[a][b])
                a += 1; b += 1
            a, b = i, j
            while a < n and b < n:
                v[a][b] -= ile 
                a += 1; b += 1
            ans -= ile 
    print(ans)
            
            
            