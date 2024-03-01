n = int(input())
v = map(int, input().split())

even, odd = 0, 0
for i in v:
    if i & 1: odd += 1
    else: even += 1

print(min(even, odd))
