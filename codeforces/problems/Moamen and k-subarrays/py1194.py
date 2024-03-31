t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = list(map(int, input().split()))
    v = [(v[x], x) for x in range(n)]
    v.sort()
    
    ans = 0
    for i in range(1, n):
        if v[i - 1][1] + 1 != v[i][1]: ans += 1
    
    if ans < k: print("YES")
    else: print("NO")