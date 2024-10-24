t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    s = sorted(v)
    l = 0; r = 0
    for i in range(n):
        if v[i] != s[i]:
            l = i 
            break; 
    
    mini = float('inf') 
    for i in range(l, n):
        if v[i] <= mini:
            r = i 
            mini = v[i] 
    
    v[l:r + 1] = v[l:r + 1][::-1]
    ans.append(v)
for u in ans:
    print(*u)
    