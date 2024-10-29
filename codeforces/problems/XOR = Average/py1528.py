t = int(input())
for _ in range(t):
    n = int(input())
    if n & 1:
        ans = [n] * n 
    else:
        ans = [1, 3] + [2] * (n - 2)
        
    print(*ans)
        
    
        