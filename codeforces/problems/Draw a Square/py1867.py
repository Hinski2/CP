t = int(input())
for _ in range(t):
    vs = [int(i) for i in input().split()]
    if all([v == vs[0] for v in vs]):
        print("YES")
    else:
        print("NO")