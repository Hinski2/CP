t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(u) for u in input().split()]
    
    if all([u == 0 for u in v]):
        print(0)
        continue
    
    l, r = 0, n - 1
    while v[l] == 0:
        l += 1
    while v[r] == 0:
        r -= 1
    
    if any([u == 0 for u in v[l: r + 1]]):
        print(2)
    else:
        print(1)
    
    