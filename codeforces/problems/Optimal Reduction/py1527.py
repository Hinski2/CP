yes, no = 'YES', 'NO'
ans = []
t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    v = zip(v[:], v[1:])
    inc = True
    ok = True
    for a, b in v:
        if inc:
            if a > b:
                inc = False
        else:
            if a < b:
                ok = False
            
            
        
    if ok:
        ans.append(yes)
    else:
        ans.append(no)

print(*ans, sep='\n')
    
    