t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    v = sorted([int(i) for i in input().split()], reverse=True)
    if sum(v) == m:
        print('NO')
        continue
    else:
        for i in range(n):
            if m == v[i]:
                v[i], v[i + 1] = v[i + 1], v[i]
            m -= v[i]
        print('YES')
        print(*v)
    