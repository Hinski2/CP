t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    if n == m == 1: print(0)
    else: print(min(m * 2 + n - 2, 2 * n + m - 2))