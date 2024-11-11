t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    if x == 2 and y == 3:
        print('YES')
    elif x <= 3 and y > x:
        print('NO')
    else:
        print('YES')