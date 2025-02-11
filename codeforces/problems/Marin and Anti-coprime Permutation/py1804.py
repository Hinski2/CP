mod = 998244353
t = int(input())
for _ in range(t):
    n = int(input())
    if n % 2:
        print(0)
        continue
    
    ans = 1
    for i in range(1, n // 2 + 1):
        ans *= i
        ans %= mod
        
    ans = ans * ans % mod
    print(ans)