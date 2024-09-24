def dist(a, b, c):
    if a > b: a, b = b, a # a is smaller
    if a <= c <= b: return 0 
    if c <= a: return a - c 
    return c - b 
    
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    closest = 1e10
    ans = 0
    
    for i in range(n): 
        ans += abs(a[i] - b[i])
        closest = min(closest, dist(a[i], b[i], b[-1]))
    ans += closest + 1
    print(ans)