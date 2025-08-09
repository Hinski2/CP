n = int(input())
v = sorted([int(u) for u in input().split()])
if sum(v[:n]) == sum(v[n:]):
    print(-1)
else:
    print(*v)