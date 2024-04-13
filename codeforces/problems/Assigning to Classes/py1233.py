t = int(input())
for _ in range(t):
    n = int(input())
    v = sorted(list(map(int, input().split())))
    print(abs(v[n - 1] - v[n]))
