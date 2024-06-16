t = int(input())
for _ in range(t):
    s = list(input())
    s[0], s[4] = s[4], s[0]
    print(*s, sep='')