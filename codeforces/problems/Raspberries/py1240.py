t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = list(map(int, input().split()))
    
    ans, cnt = k, 0
    for u in v:
        if u % 2 == 0: cnt += 1
        if u % k == 0: ans = 0
        ans = min(ans, k - u % k)
    if k == 4:
        if cnt >= 2: ans = 0
        elif cnt == 1: ans = min(ans, 1)
        else: ans = min(ans, 2)
    
    print(ans)
        