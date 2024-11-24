t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    v = sorted([int(i) for i in input().split()])
    mini_pos = float('inf')
    for u in v:
        if u > 0: mini_pos = min(u, mini_pos)
    
    ok = mini_pos < float('inf')
    for i in range(1, n):
        if v[i] <= 0: ok &= v[i] - v[i - 1] >= mini_pos
    if ok:
        ans.append(len([i for i in v if i <= 0]) + 1)
    else:
        ans.append(len([i for i in v if i <= 0]))

print(*ans, sep='\n')
        
        
        
    