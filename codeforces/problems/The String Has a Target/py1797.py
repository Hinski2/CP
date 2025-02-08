t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input())
    m = min(s)
    s = s[::-1]
    s.remove(m)
    s.append(m)
    s = s[::-1]
    print(*s, sep='')
        