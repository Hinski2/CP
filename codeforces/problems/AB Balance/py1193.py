t = int(input())
for _ in range(t):
    s = input()
    if s[0] == s[-1]:
        print(s)
    else:
        ss = s[-1] + s[1:]
        print(ss)