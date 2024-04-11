n, k = map(int, input().split())
v = list(map(int, input().split()))
l, r = 0, n - 1
ans = 0
while l <= r:
    if v[l] <= k:
        ans += 1
        l += 1
    elif v[r] <= k:
        ans += 1
        r -= 1
    else:
        break
    
print(ans)
        