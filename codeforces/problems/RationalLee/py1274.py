t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = sorted(list(map(int, input().split())),reverse=True)
    w = sorted(list(map(int, input().split())))
    
    idx, l, r, ans = k, 0, n - 1, 0
    for i in range(k):
        if w[i] > 1:
            idx = i
            break
        ans += a[l] * 2
        l += 1
    for j in range(k - 1, idx - 1, -1):
        i = w[j]
        ans += a[l] + a[r]
        r += 1 - i
        l += 1
    print(ans)
        
    