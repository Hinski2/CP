t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    if all([i == v[0] for i in v]):
        print(len(v))
    else:
        print(1)