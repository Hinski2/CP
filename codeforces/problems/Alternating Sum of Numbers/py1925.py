t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    print(sum(v[::2]) - sum(v[1::2]))
    