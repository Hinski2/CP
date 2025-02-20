y, k, n = map(int, input().split())
ok = False
for x in range(-y % k, n + 1, k):
    if 1 <= x + y <= n and x > 0 and (x + y) % k == 0:
        print(x, end=' ')
        ok = True

if not ok:
    print(-1)