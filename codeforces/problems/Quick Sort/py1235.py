t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = list(map(int, input().split()))
    look_for = 1
    for u in v:
        if u == look_for:
            look_for += 1

    print((n - look_for + k) // k)
