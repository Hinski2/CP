t = int(input())
for _ in range(t):
    n, l, r, k = map(int, input().split())
    v = map(int, input().split())
    a = sorted([i for i in v if l <= i <= r])
    ans, i = 0, 0
    while k > 0 and i < len(a):
        if a[i] <= k:
            ans += 1
            k -= a[i]
        i += 1

    print(ans)