t = int(input())
for _ in range(t):
    n = int(input())
    v = map(int, input().split())
    v = list(v)
    v.sort()
    ans = 2 * (v[n - 1] - v[0] + v[n - 2] - v[1])
    print(ans)