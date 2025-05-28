t = int(input())
for _ in range(t):
    s = int(input())
    
    ok = False 
    for i in range(100):
        if ok:
            break
        
        for j in range(100):
            if((i + j) ** 2 == s):
                print(i, j)
                ok = True 
                break
            elif (i + j) ** 2 > s:
                break
    
    if not ok:
        print(-1) 
        
