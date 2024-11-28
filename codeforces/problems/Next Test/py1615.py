n = int(input())
v = sorted([int(i) for i in input().split()])
idx = 0
for i in range(1, n + 2):
    if idx >= len(v) or v[idx] != i:
        print(i)
        break 
    else: 
        idx += 1