t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = [len(u.replace(' ', '')) for u in input().split("1")]
    
    ans = 0
    for u in v:
        if u >= k: ans += (u + 1) // (k + 1)
    print(ans)
