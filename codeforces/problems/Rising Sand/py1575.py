t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = list(map(int, input().split()))
    v = zip(v[0:], v[1:], v[2:])
    ans = 0
    if k == 1:
        print((n - 1) // 2)
    else:
        for u in v:
            if u[1] > u[0] + u[2]:
                ans += 1
        print(ans)