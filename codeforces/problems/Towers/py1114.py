n = int(input())
v = map(int, input().split())

d = {}
for i in v:
    d[i] = d.get(i, 0) + 1

ans = 0
for i in d:
    ans = max(ans, d[i])

print(ans, len(d))

    