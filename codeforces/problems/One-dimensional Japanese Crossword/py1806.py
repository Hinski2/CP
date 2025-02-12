n = int(input())
v = [len(u) for u in input().split('W') if len(u)]
print(len(v))
print(*v)