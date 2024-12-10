t = int(input())
for _ in range(t):
    n = int(input())
    l = -1; r = int(1e9 + 7)
    while r - l > 1:
        mid = (l + r) // 2 
        if mid * mid >= n: r = mid 
        else: l = mid
    print(r - 1)