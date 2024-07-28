t = int(input())
for _ in range(t):
    v = list(map(int, input().split()))
    ans = 0
    while v[1] and v[2]:
        if v[0]:
            ans += 1
            v[2] -= 1
            v[0] -= 1
        else:
            ans += 1
            v[1] -= 1
            v[2] -= 1
        v = sorted(v)
   
    v = [x % 2 for x in v]
    if sum(v):
        print(-1)
    else:
        print(ans)
            
    