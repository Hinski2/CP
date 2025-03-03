t = int(input())
for _ in range(t):
    n = int(input())
    n -= 1
    if n % 3 == 0:
        print('YES')
    else:
        print('NO')