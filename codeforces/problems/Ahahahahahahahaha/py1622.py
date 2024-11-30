t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    one = sum(v)
    zero = n - one
    
    ans = [] 
    if one <= n // 2:
        ans = [0] * zero
    else:
        if one % 2:
            ans = [1] * (one - 1)
        else:
            ans = [1] * (one)
    
    print(len(ans))
    print(*ans)
    
    