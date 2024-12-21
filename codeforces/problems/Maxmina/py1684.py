t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = [int(i) for i in input().split()]
    if any([i == 1 for i in v]):
        print("YES")
    else:
        print("NO")