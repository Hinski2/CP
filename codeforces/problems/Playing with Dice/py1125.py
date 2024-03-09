a, b = map(int, input().split())
cnt = [0, 0, 0]
for i in range(1, 7):
    if abs(a - i) < abs(b - i): cnt[0] += 1
    elif abs(a - i) > abs(b - i): cnt[2] += 1
    else: cnt[1] += 1

print(*cnt, sep=' ')
