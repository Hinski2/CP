n = int(input())
vs = [int(v) for v in input().split()]
ans = 0
for i in range(1, n - 1):
    if vs[i - 1] == vs[i + 1] == 1 and vs[i] == 0:
        ans += 1
        vs[i + 1] = 0
print(ans)
        