MOD = int(1e9 + 7)
s = input()

if s.count('w') or s.count('m'):
    print(0)
else:
    n = len(s)
    dp = [1 for _ in range(n)]
    for i in range(1, n):
        if s[i] == s[i - 1] and s[i] in ['u', 'n']:
            dp[i] = dp[i - 1] + dp[i - 2]
        else:
            dp[i] = dp[i - 1]
        dp[i] %= MOD 
        
    print(dp[n - 1])
        

