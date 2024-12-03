t = int(input())
for _ in range(t):
    n = int(input())
    s = [int(i) for i in list(input())]
    if n == 1: 
        print(0)
    else:
        ans = 0
        v = list(zip(s[:], s[1:]))
        ans += 2 * v.count((0, 0))
        v = list(zip(s[:], s[1:], s[2:]))
        ans += v.count((0, 1, 0))
        print(ans)