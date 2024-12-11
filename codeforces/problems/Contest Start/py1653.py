t = int(input())
ans = []
for _ in range(t):
    n, x, t = map(int, input().split())
    
    i = t // x 
    a = min(n - 1, i - 1) * min(n, i) // 2
    a += max(0, n - i) * i 
    ans.append(a)
        
print(*ans, sep='\n')