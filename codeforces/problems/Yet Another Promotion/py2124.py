t = int(input())
for _ in range(t):
    a, b = map(int, input().split())    
    n, m = map(int, input().split())
    
    q = n // (m + 1)
    r = n % (m + 1)
    
    ans = q * min(a * m, b * (m + 1)) + r * min(a, b)  
    print(ans)
    
