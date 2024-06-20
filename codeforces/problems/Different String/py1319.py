def xd(s):
    for i in range(len(s)):
        if s[0] != s[i]:
            s[0], s[i] = s[i], s[0]
            print("YES")
            print(*s, sep='')
            return 
    print("NO")
    
t = int(input())
for _ in range(t):
    s = list(input())
    xd(s)
                
    