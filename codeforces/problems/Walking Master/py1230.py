t = int(input())
for _ in range(t):
    x, y, a, b = map(int, input().split())
    if y <= b and a + y <= x + b:
        print(b - y + x + b - y - a)
    else:
        print(-1)