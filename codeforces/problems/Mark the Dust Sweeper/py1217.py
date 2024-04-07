t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    i = 0
    while i < n and v[i] == 0:
        i += 1
    ans = 0
    for j in range(i, n - 1):
        ans += v[j] if v[j] else 1
    print(ans)