t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    v = []
    for i in range(n):
        v.append(input())
 
    maxpos, maxnu = -1, -1
    for i in range(n):
        cnt = 0
        for j in range(m):
            if v[i][j] == '#': 
                cnt += 1
        if cnt > maxnu:
            maxnu = cnt 
            maxpos = i
 
    print(maxpos + 1, end=' ')
    maxpos, maxnu = -1, -1
    for j in range(m):
        cnt = 0
        for i in range(n):
            if v[i][j] == '#': 
                cnt += 1
        if cnt > maxnu:
            maxnu = cnt 
            maxpos = j 
            
    print(maxpos + 1)
 