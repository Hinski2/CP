t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    
    if all(u % 2 == 0 for u in v): 
        print(0)
    else:
        m = max([u for u in v if u % 2])
        v = sorted(v)
        ans, extra = 0, 0
        for u in v:
            if u % 2 == 1:
                continue
            elif u > m and not extra:
                m += u 
                extra = True
                ans += 2
            else:
                m += u
                ans += 1
        print(ans)