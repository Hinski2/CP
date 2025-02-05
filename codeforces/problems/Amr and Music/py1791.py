n, k = map(int, input().split())
vs = sorted(zip([int(u) for u in input().split()], range(1, n + 1)))

s, idx = 0, 0
ans = []
while idx < n and s + vs[idx][0] <= k:
    s += vs[idx][0]
    ans.append(vs[idx][1])
    idx += 1
    
print(len(ans))
print(*ans)
    