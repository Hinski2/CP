n = int(input())
v = list(map(int, input().split()))
v.sort()

ans = [0] * n
j = 0

print((n - 1) // 2)
for i in range(1, n, 2):
    ans[i] = v[j]
    j += 1

for i in range(0, n, 2):
    ans[i] = v[j]
    j += 1

print(*ans, sep=' ')



