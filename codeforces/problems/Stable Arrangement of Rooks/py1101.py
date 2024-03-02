t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    m = [['.' for i in range(n)] for j in range(n)]

    if k > (n + 1) // 2:
        print(-1)
        continue

    for i in range(0, k):
        m[2 * i][2 * i] = 'R'
    
    for i in range(n):
        for j in range(n):
            print(m[i][j], end='')
        print()