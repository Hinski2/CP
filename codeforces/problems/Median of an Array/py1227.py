t = int(input())
for _ in range(t):
    n = int(input())
    s = (n + 1) // 2 - 1
    v = sorted(list(map(int, input().split())))
    print(v[s:].count(v[s]))