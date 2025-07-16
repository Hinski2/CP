n = int(input())
v = list(map(int, input().split()))
if v == sorted(v):
    print(0)
else:
    mini1, mini2, last = v[0], int(1e9 + 7), v[0]
    ok = True
    for idx, u in enumerate(v):
        if mini2 != int(1e9 + 7):
            if u < last or u > mini1:
                ok = False
                
        else:
            if u < last and u <= mini1:
                mini2 = idx
            elif u < last:
                ok = False
        
        last = u
    
    if ok: 
        print(n - mini2)
    else:
        print(-1)
    
    