t = int(input())
while t:

    t -= 1
    n, m, r, c = map(int, input().split())
    mat = [input() for i in range(n)]

    if mat[r - 1][c - 1] == 'B':
        print(0)
        continue

    find_back = False
    for i in range(n):
        for j in range(m):
            if mat[i][j] == 'B':
                find_back = True
    if not find_back:
        print(-1)
        continue
    
    find_back = False
    for j in range(m):
        if mat[r - 1][j] == 'B': find_back = True
    for i in range(n):
        if mat[i][c - 1] == 'B': find_back = True
    
    if find_back:
        print(1)
    else:
        print(2)