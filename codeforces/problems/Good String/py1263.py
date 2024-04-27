t = int(input())
for _ in range(t):
    v = input()
    possible_combinations = []
    for i in range(10):
        for j in range(10):
            possible_combinations.append([i, j])
                
    ans = 0
    for u in possible_combinations:
        subans, idx, mod, pos = 0, 0, len(u), -1
        while v.find(str(u[idx]), pos + 1) != -1:
            subans += 1
            pos = v.find(str(u[idx]), pos + 1)
            idx = (idx + 1) % mod
            
        if u[0] != u[1] and subans & 1: subans -= 1
        ans = max(ans, subans)
    print(len(v) - ans)
    