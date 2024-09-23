t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = list(map(int, input().split()))
    
    ans, coins = 0, 0
    for u in v:
        if u >= k:
            coins += u 
        elif u == 0 and coins: 
            coins -= 1
            ans += 1
    
    print(ans) 
        
    