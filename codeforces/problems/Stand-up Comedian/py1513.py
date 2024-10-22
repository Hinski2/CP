t = int(input())
odp = []
for _ in range(t):
    v = list(map(int, input().split()))
    if v[0] == 0: 
        odp.append(1)
        continue
    
    ans = v[0]
    ans += min(v[1], v[2]) * 2 
    ans += min(v[0] + 1, abs(v[1] - v[2]) + v[3])
    odp.append(ans)
    
print(*odp, sep='\n')
    
