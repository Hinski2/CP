n = int(input())
v = list(map(int, input().split()))
s = sum(v)
ans = 0
for i in range(1, 6):
    if (s + i) % (n + 1) != 1: ans += 1
print(ans)