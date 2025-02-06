t = int(input())
for _ in range(t):
    n = int(input())
    vs = [int(i) for i in input().split()]
    if any([a + a > b and b + b > a for a, b in zip(vs[0:], vs[1:])]):
        print('YES')
    else:
        print('NO')