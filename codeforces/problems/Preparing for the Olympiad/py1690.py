t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    ans = a[-1]
    for i in range(n - 1):
        ans += max(0, a[i] - b[i + 1])
    print(ans)