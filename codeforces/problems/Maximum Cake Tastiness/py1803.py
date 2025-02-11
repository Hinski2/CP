t = int(input())
for _ in range(t):
    n = int(input())
    v = sorted([int(i) for i in input().split()])
    print(v[-1] + v[-2])