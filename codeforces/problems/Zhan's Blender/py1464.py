t = int(input())
for _ in range(t):
    n = int(input())
    x, y = map(int, input().split())
    print((n + min(x, y) - 1) // min(x, y))