t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = [(a[i], b[i]) for i in range(n)]
    c.sort()
    
    for i in range(n):
        a[i] = c[i][0]
        b[i] = c[i][1] 
        
    #wypisanie
    print(*a)
    print(*b)