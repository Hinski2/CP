t = int(input())
for _ in range(t):
    n = int(input())
    v = sorted([int(i) for i in input().split()])
    l = 2; r = n - 2
    lsum = v[0] + v[1]; rsum = v[-1]
    while l < r:
        if lsum < rsum:
            print('YES')
            break
        lsum += v[l]; l += 1
        rsum += v[r]; r -= 1 
    else:
        if lsum < rsum:
            print("YES")
            continue
        else:
            print('NO')
        
    
        