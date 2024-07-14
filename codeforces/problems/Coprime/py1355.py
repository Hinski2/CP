from math import gcd
t = int(input())
for _ in range(t):
    n = int(input())
    v = [0] + list(map(int, input().split()))
    pos = [-1] * 1001 
    for i in range(1, len(v)):
        pos[v[i]] = i 
    
    ans = -1
    for j in range(1, len(v)):
        if j != pos[v[j]]: continue
        for i in range(1, 1001):
            if pos[i] != -1 and gcd(i, v[j]) == 1:
               ans = max(ans, j + pos[i])
    
    print(ans)

        
    