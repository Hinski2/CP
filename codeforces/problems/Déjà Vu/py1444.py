t = int(input())
for _ in range(t):
    s = input()
    if all(i == 'a' for i in s):
        print('NO')
        
    else:
        print('YES')
        if 'a' + s != ('a' + s)[::-1]:
            print('a' + s)
        else:
            print(s + 'a')
    