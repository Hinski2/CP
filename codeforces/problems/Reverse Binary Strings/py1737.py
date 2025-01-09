t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    a, b = 0, 0
    for i in range(1, n):
        if s[i - 1] == s[i] == '0':
            a += 1
            i += 1
        elif s[i - 1] == s[i] == '1':
            b += 1
            i += 1
        
    x = min(a, b)
    ans = x
    a -= x
    b -= x
    ans += a 
    ans += b 
    print(ans)