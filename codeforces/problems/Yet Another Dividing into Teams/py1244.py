t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    v.sort()
    ans = False
    for i in range(0, n - 1):
        if v[i + 1] - v[i] <= 1:
            ans = True
    print(2 if ans else 1)