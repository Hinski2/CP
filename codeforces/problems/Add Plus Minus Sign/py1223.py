t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    cnt = s[0] == '1'
    s = s[1:]
    for u in s:
        if u == '0':
            print('+', end='')
        elif cnt:
            print('-', end='')
            cnt = 0
        else:
            print('+', end='')
            cnt = 1
    print()