t = int(input())
for _ in range(t):
    n = int(input())
    v = [n - i + 1 for i in range(1, n + 1)]
    if n == 3:
        print("3 1 2")
        print("3 2 1")
        print("2 3 1")
    else:
        for _ in range(n):
            print(*v)
            v = [v[-1]] + v[: -1]