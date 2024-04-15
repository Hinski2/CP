t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))

    r = [v[i] for i in range(0, n) if i == n - 1 or v[i] != v[i + 1]]
    r = [int(1e9 + 7)] + r + [int(1e9 + 7)]
    ans = 0
    for i in range(1, len(r) - 1):
        if r[i - 1] > r[i] < r[i + 1]: ans +=1

    print("YES" if ans == 1 else "NO")
