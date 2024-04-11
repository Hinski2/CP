t = int(input())
for _ in range(t):
    s = input()
    f = False
    for i in range(1, len(s)):
        if int(s[:i]) < int(s[i:]) and s[i] != '0':
            print(int(s[:i]), int(s[i:]))
            f = True
            break
    if not f:
        print(-1)
    
            