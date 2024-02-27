t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    asort = sorted(a)

    d1 = {}
    d2 = {}
    for i in range(k):
        d1[a[i]] = d1.get(a[i], 0) + 1  
        d2[asort[i]] = d2.get(asort[i], 0) + 1 

    ans = 0
    for i in d2:
        if i in d1: ans += d2[i] - d1[i]
        else: ans += d2[i]
    print(ans)
