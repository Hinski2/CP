t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input())
    
    x, v = 0, []
    for i in range(n):
        if s[i] == 'L': v.append((n - 1 - i) - i); x += i
        else: v.append(i - (n - 1 - i)); x += n - 1 - i
    
    v = sorted(v)[::-1]
    ans = []
    for i in range(n):
        if v[i] > 0: x += v[i]
        ans.append(x)
    
    print(*ans)
    
    
    
    