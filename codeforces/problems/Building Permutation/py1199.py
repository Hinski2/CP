n = int(input())
v = list(map(int, input().split()))
v.sort()
ans = 0
for i in range(n):
    ans += abs(i + 1 - v[i])
print(ans)