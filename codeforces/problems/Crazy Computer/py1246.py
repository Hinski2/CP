n, k = map(int, input().split())
v = list(map(int, input().split()))
now, last = 0, 0
for u in v:
    if u - last > k:
        now = 1
    else:
        now += 1
    last = u
print(max(1, now))