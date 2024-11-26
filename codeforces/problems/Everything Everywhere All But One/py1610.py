t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    s = sum(v)
    if any([n*u == s for u in v]):
        print('YES')
    else:
        print('NO') 