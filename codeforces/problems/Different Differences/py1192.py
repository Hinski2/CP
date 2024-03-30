def make(x, k):
    return [(i + 2 if i < x - 1 else 1) for i in range(k)]

t = int(input())
for _ in range(t):
    k, n = map(int, input().split())
    ans = 1
    for i in range(1, k):
        a = make(i, k - 1)
        if(sum(a) <= n - 1):
            ans = i
    
    res = [1]
    a = make(ans, k - 1)
    for x in a:
        res.append(res[-1] + x)
    print(*res)
        