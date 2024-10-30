t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    if v[0] != min(v):
        print("alice")
    else:
        print("bob")
    