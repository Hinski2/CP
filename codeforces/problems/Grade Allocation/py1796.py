t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    vs = [int(i) for i in input().split()]
    print(min(sum(vs), m))