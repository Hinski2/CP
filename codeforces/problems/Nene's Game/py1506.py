t = int(input())
for _ in range(t):
    k, q = map(int, input().split())
    a = list(map(int, input().split()))
    v = list(map(int, input().split()))
    
    ans = [0] * q
    for i in range(q):
        ans[i] = min(v[i], a[0] - 1)
    print(*ans)
        
    

