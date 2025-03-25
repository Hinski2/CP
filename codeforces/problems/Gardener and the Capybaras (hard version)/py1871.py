t = int(input())
for _ in range(t):
    s = input()
    if s[0] == s[-1]:
        print(s[0], s[1:-1], s[-1])
    elif 'a' in s[1:-1]:
        pos = s[1:-1].index('a') + 1
        print(s[0:pos], s[pos], s[pos+1:])
    else:
        print(s[0], s[1:-1], s[-1])
