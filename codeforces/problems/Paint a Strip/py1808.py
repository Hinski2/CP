from math import log2, floor
t = int(input())
for _ in range(t):
    n = int(input())
    ans, cur = 1, 1
    while cur < n:
        ans += 1
        cur = (cur + 1) * 2
    
    print(ans)
    