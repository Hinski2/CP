n, q = map(int, input().split())
v = list(map(int, input().split()))
l = [0] + [max(0, v[i] - v[i + 1]) for i in range(n - 1)]
r = [0] + [max(0, v[i] - v[i - 1]) for i in range(1, n)]
for i in range(n - 1):
    l[i + 1] += l[i]
    r[i + 1] += r[i]

for _ in range(q):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    
    if a < b: print(l[b] - l[a])
    else: print(r[a] - r[b])



