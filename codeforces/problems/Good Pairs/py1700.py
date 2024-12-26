t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    print(v.index(min(v)) + 1, v.index(max(v)) + 1)