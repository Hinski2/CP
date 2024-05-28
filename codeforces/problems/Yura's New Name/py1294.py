t = int(input())
for _ in range(t):
    s = input()
    if s == '^':
        print(1)
        continue
    
    last = '_'
    i, ans = 0, 0
    while i < len(s):
        if s[i] == '_' == last:
            last = '^'
            ans += 1
        else:
            last = s[i]
            i += 1
    
    if last == '_':
        ans += 1
    print(ans)