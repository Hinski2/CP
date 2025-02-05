t = int(input())
for _ in range(t):
    n = int(input())
    vs = sorted([int(i) for i in input().split()])
    print(sum(vs[0::2]))