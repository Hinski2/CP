t = int(input())
for i in range(t):
    n = int(input())
    v = list(map(int, input().split()))

    a = [n + 1 - v[i] for i in range(n)]
    print(*a, sep= ' ')