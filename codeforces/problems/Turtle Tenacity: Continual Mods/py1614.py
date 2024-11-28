t = int(input())
for _ in range(t):
    n = int(input())
    v = sorted([int(i) for i in input().split()])
    
    if v[0] != v[1]:
        print('YES')
    else:
        if any([v[i] % v[0] for i in range(1, n)]):
            print('YES')
        else:
            print('NO')