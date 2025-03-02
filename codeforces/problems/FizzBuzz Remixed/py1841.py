t = int(input())
for _ in range(t):
    n = int(input())
    ans = n // 15
    n -= ans * 15
    ans *= 3
    ans += min(n, 2) + 1
    print(ans)
    