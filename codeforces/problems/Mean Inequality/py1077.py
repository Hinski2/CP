t = int(input())
for _ in range(t):
    n = int(input())
    l = sorted(list(map(int, input().split())))

    a = l[:n]
    b = l[n:]

    for i, j in zip(a, b):
        print(j, i, '', end='')
    print()