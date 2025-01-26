t = int(input())
for _ in range(t):
    n, k, x = map(int, input().split())
    if min(n, x + 1) < k:
        print(-1)
    elif x == k:
        ans = (k - 1) * k // 2 + (n - k) * (k - 1)
        print(ans)
    else:
        ans = (k - 1) * k // 2 + (n - k) * x 
        print(ans)
        