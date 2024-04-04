a, b = map(int, input().split())
if a < b: a, b = b, a
ans, t = 0, 0
if a == 1 and b == 1:
    print(0)
    exit()
while a or b:
    t = 0
    if a == 2:
        ans += 1
        break
    while a > 2:
        a -= 2
        ans += 1
        t += 1
        
    b += t
    a, b = b, a

print(ans)
    

    

    
    