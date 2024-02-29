t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    s = sum(v)
    div = False
    for i in v:
        if i % 3 == 1: div = True

    if s % 3 == 0: print(0)
    elif s % 3 == 2: print(1)
    elif s % 3 == 1 and div: print(1)
    else: print(2)
    
