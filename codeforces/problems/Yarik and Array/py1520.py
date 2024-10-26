t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    
    local_max = 0; global_max = float('-inf'); last = None
    for i in range(n):
        if (last == None or last % 2 != v[i] % 2) and local_max > 0:
            local_max += v[i]
            last = v[i] 
        else:
            local_max = v[i]
            last = v[i]
        global_max = max(global_max, local_max)
    
    ans.append(global_max)
print(*ans, sep='\n')
     