t = int(input())
for _ in range(t):
    n, s = map(int, input().split())
    v = list(map(int, input().split()))
    
    s += sum(v)
    suma, cnt = 0, 0
    
    for i in range(1, s + 1):
        if suma >= s: break
        
        suma += i
        cnt = i
    
    if suma != s or max(v) > cnt or cnt <= n:
        print("NO")
    else:
        print("YES")
    
    