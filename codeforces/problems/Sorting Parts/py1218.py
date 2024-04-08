t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    print("NO" if all(v[i] <= v[i + 1] for i in range(0, n - 1)) else "YES")