t = int(input())
for _ in range(t):
    ans, p = 0, 1
    n, k = map(int, input().split())
    if k == 1:
        print(n)
        continue
    while p * k <= n:
        p *= k
    
    while n:
        while n // p == 0:
            p //= k
        
        x = n // p
        ans += x 
        n -= x * p 
    
    print(ans)
        
    