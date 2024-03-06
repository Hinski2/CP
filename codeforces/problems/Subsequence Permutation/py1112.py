t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    v = [ord(i) for i in s]
    vs = sorted(v)

    cnt = 0
    for i in range(n):
        if v[i] != vs[i]: cnt += 1
    print(cnt)