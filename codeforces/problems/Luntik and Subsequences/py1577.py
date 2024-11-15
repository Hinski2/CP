t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    print(v.count(1) * (2 ** v.count(0)))