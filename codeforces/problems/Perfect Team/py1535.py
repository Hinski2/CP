def ok(c, m, n, mid):
    left = c - mid + m - mid + n 
    return left >= mid
    
    
t = int(input())
for _ in range(t):
    c, m, n = map(int, input().split())
    l = 0; r = min(c, m); mid = 0
    while(l < r):
        mid = (l + r + 1) // 2
        if ok(c, m, n, mid):
            l = mid 
        else:
            r = mid - 1
    
    print(l)
        