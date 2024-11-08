t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    if sum(v) % n == 0: print(0)
    else: print(1)