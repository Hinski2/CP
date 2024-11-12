def find_div(x):
    i = 2
    div = [1]
    while i * i <= x:
        if x % i == 0:
            div.append(i)
            div.append(x // i)
        i += 1
    return div 

t = int(input())
a = []
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    
    ans = 0
    div = find_div(n)
    for d in div:
        divided = [sum(v[i:i + d]) for i in range(0, n, d)]
        ans = max(ans, max(divided) - min(divided))
    a.append(ans)
print(*a, sep='\n')   
    
        
        