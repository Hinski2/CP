n = int(input())
v = [[int(i) for i in input().split()] for _ in range(n)]

if any([u[0] != u[1] for u in v]):
    print('rated')
else:
    v = zip(v[:], v[1:])
    if all([u[0][0] >= u[1][0] for u in v]):
        print('maybe')
    else:
        print('unrated')