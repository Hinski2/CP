t = int(input())
for _ in range(t):
    s = input()
    map = {}
    for i in s:
        map[i] = map.get(i, 0) + 1

    maks = 0
    for i in map:
        maks = max(maks, map[i])
    
    if len(map) == 1: print(-1)
    elif len(map) > 2: print(4)
    elif len(map) == 2 and maks == 3: print(6)
    else: print(4)