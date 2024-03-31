t = int(input())
for _ in range(t):
    s = input()
    removeLow, removeUp = 0, 0
    ans = ""
    for i in range(len(s) - 1, -1, -1):
        if s[i] == 'b': removeLow += 1
        elif s[i] == 'B': removeUp += 1
        elif s[i] >= 'a':
            if removeLow: removeLow -= 1
            else: ans += s[i]
        else:
            if removeUp: removeUp -= 1
            else: ans += s[i]
    
    print(ans[::-1])