t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    ans = n * a if 2 * a <= b else n // 2 * b + a * (n % 2)
    print(ans)