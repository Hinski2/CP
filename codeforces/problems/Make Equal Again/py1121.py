t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))

    l, lidx = v[0], 0
    while lidx + 1 < n and v[lidx+1] == l:
        lidx += 1
    
    r, ridx = v[-1], len(v)-1
    while ridx -1 >= 0 and v[ridx-1] == r:
        ridx -= 1

    if(lidx == n-1):
        print(0)
    elif l == r:
        print(ridx - lidx - 1)
    else:
        print(min(ridx, n - lidx - 1))
