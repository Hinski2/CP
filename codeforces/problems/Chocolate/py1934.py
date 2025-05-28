n = int(input())
v = [int(i) for i in input().split()]
if not v.count(1):
    print(0)
else: 
    l = 0
    while l < n and v[l] == 0:
        l += 1
    
    r = n - 1
    while r >= 0 and v[r] == 0:
        r -= 1

    ans = 1
    for rr in range(l, r + 1):
        if v[rr] == 1:
            ans *= max(1, rr - l)
            l = rr

    print(ans) 