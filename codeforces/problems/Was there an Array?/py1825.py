t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    if any([u == (1, 0, 1) for u in zip(v[0:], v[1:], v[2:])]):
        print('NO')
    else:
        print('YES')