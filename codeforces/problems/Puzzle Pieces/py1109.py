t = int(input())
for _ in range(t):
    v = list(map(int, input().split()))
    v = sorted(v)

    if v[0] == 1 or (v[0] == v[1] == 2):
        print("YES")
    else:
        print("NO")