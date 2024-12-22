from math import gcd

t = int(input())
for _ in range(t):
    n = int(input())
    v = sorted([int(i) for i in input().split()])
    
    ok = False
    for i in range(n):
        for j in range(i + 1, n):
            if(gcd(v[i], v[j]) <= 2):
                ok = True
                break
    
    if ok:
        print("YES")
    else:
        print("NO") 