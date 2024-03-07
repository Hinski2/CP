t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    if b >= a:
        print(b)
        continue
    if c <= d:
        print(-1)
        continue

    a -= b
    delta = c - d
    print(b + (a + delta - 1) // delta * c)