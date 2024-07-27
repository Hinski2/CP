t = int(input())
for _ in range(t):
    n, ans = int(input()), 0
    ans += n // 4
    n -= ans * 4
    if n: ans += 1
    print(ans)
    