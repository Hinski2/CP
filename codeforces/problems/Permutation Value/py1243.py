t = int(input())
for _ in range(t):
    n = int(input())
    v = [0] * n
    v[0], v[-1] = 1, 2
    cnt = 3
    for i in range(1, n - 1):
        v[i] = cnt
        cnt += 1
    print(*v)