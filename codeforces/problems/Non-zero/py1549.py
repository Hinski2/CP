t = int(input())
for i in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    z = v.count(0)
    ans = z 
    
    if sum(v) + z == 0:
        x = max(v)
        if x == 0: x = 1
        
        x += 1
        ans += 1
        if x == 0:
            x += 1
            ans += 1
        
    print(ans)
        