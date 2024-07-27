t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    mat = []
    for i in range(n):
        mat.append(list(input()))
    
    for i in range(0, n, k):
        for j in range(0, n, k):
            print(mat[i][j], end='')
        print()
    
    