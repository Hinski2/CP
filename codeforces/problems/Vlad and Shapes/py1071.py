def solve():
    n = int(input())
    matrix = [input() for i in range(n)]
    for i in range(n):
        for j in range(n):
            if int(matrix[i][j]) == 1:
                if int(matrix[i + 1][j]) == 1 & int(matrix[i][j + 1]) == 1:
                    return 'SQUARE'
                else:
                    return 'TRIANGLE'

t = int(input())
while(t):
    t -= 1
    print(solve())

