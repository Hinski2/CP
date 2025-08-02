t = int(input())
for _ in range(t):
    s = input()
    
    if all([u == '1' for u in s]):
        m = len(s)
        print(m * m)
        continue
    
    s = s + s
    s = [len(u) for u in  s.split('0')]
    m = max(s)
    
    ans, i = 0, 1
    while m >= i:
        ans = max(ans, m * i) 
        m -= 1
        i += 1
        
    print(ans)
