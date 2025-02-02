t = int(input())
for _ in range(t):
    n, z = map(int, input().split())
    v = [int(i) | z for i in input().split()]
    print(max(v))