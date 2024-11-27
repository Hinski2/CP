mod = int(1e9 + 7)

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = [int(i) for i in input().split()]
    
    suma = 0 
    l_max, g_max = 0, 0
    for u in v:
        suma += u 
        l_max += u 
        l_max = max(l_max, 0)
        g_max = max(g_max, l_max)
        
        
    suma %= mod 
    g_max %= mod 
    p = 1 
    for i in range(k):
        p *= 2 
        p %= mod 
        
    ans = (suma + g_max * p - g_max) % mod 
    print(ans) 
    
    