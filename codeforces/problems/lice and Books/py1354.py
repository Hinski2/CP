t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    print(v[-1] + max(v[:-1]))
    