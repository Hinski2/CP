t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    if all(u == v[0] for u in v):
        print('NO')
    elif min(v[1:]) == max(v[1:]):
        print('YES')
        print(''.join(['B'] * 2 + ['R'] * (n - 2)))
    else:
        print('YES')
        print(''.join(['B'] * 1 + ['R'] * (n - 1)))
        
        