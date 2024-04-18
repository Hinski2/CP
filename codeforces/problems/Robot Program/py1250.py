t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    print(max(x, y) * 2 - 1 + (1 if x == y else 0))