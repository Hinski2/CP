t = int(input())
for _ in range(t):
    n = int(input())
    p = []
    m = [list(input()) for i in range(n)]
    for i in range(n):
        for j in range(n):
            if(m[i][j] == '*'): p.append([i, j])
    
    p.append(p[0])
    p.append(p[1])
    if p[0][0] == p[1][0]:
        p[2][0] = (p[2][0] + 1) % n
        p[3][0] = (p[3][0] + 1) % n
    elif p[0][1] == p[1][1]:
        p[2][1] = (p[2][1] + 1) % n
        p[3][1] = (p[3][1] + 1) % n
    else:
        p[2][0], p[3][0] = p[3][0], p[2][0]
    
    m[p[2][0]][p[2][1]] = '*'
    m[p[3][0]][p[3][1]] = '*'
    
    for i in range(n):
        print(*m[i], sep='')
    
        
    