def div(n):
    dividers = {1:1}
    i = 2
    while i * i <= n: 
        while n % i == 0:
            dividers[i] = dividers.get(i, 0) + 1
            n //= i
        i += 1
            
    if n != 1:
        dividers[n] = dividers.get(n, 0) + 1
    
    return dividers
    
t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(u) for u in input().split()]
    
    dividers = {}
    for u in v:
        for k, v in div(u).items():
            dividers[k] = dividers.get(k, 0) + v
    
    for k, v in dividers.items():
        if v % n:
            print('NO')
            break 
    else:
        print('YES')
            