t = int(input())
for _ in range(t):
    b, x, y = map(int, input().split())
    c1, c2 = map(int, input().split())
   
    ans = 0 
    if c1 > c2:
        ile = min(b // 2, x)
        ans += ile * c1 
        b -= 2 * ile 
        x -= ile 
    else: 
        ile = min(b // 2, y)
        ans += ile * c2 
        b -= 2 * ile 
        y -= ile 
    
    if x: 
        ile = min(b // 2, x)
        ans += ile * c1 
        b -= 2 * ile 
    if y: 
        ile = min(b // 2, y)
        ans += ile * c2 
        b -= 2 * ile 
    print(ans)