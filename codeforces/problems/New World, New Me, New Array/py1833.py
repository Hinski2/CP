t = int(input())
for _ in range(t):
    n, k, p = map(int, input().split())
    if abs(k) > abs(n * p):
        print(-1)
    else:
        ans = 0
        if k >= 0:
            ans = (k + p - 1) // p
        else:
            ans = -(k - p + 1) // p
            
        print(ans)