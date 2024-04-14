t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    for i in range(m):
        x = map(int, input().split())
    print("YES" if m < n else "NO")

