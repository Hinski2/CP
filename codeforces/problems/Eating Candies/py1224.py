t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    
    l, r = 0, n - 1
    suml, sumr = 0, 0
    ans = 0
    while l < r:
        suml += v[l]
        l += 1
         
        while l <= r and suml >= sumr + v[r]:
            sumr += v[r]
            r -= 1
            
            if suml == sumr:
                ans = l + n - r - 1
    
    print(ans)
                
        
            