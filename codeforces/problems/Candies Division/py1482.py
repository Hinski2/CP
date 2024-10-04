t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    ans = k * (n // k) + min(k // 2, n % k)
    print(ans)