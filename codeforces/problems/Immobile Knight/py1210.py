v = [(2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1)]
for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = (n, m)
    for i in range(1, n):
        for j in range(1, m):
            valid = False
            for ruch in v:
                _i = ruch[0] + i
                _j = ruch[1] + j
                if 0 < _i <= n and 0 < _j <= m: valid = True
            
            if not valid:
                ans = (i, j)
                break
    print(*ans)