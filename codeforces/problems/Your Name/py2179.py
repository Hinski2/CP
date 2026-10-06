t = int(input())
for _ in range(t):
    n = int(input())
    a, b = input().split()

    if sorted(a) == sorted(b):
        print("YES")
    else:
        print("NO")
