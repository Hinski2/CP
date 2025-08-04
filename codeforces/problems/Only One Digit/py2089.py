t = int(input())
for _ in range(t):
    x = [int(u) for u in input()]
    y = 0
    while not y in x:
        y += 1
    print(y)
