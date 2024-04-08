n = int(input())
v = []
for _ in range(n):
    a, b = map(int, input().split())
    v.append((a, b))
    
ans = 0
for i in v:
    f = [0] * 4
    for j in v:
        if i == j: continue
        if i[0] == j[0] and i[1] > j[1]: f[0] = 1
        elif i[0] == j[0] and i[1] < j[1]: f[1] = 1
        elif i[1] == j[1] and i[0] > j[0]: f[2] = 1
        elif i[1] == j[1] and i[0] < j[0]: f[3] = 1
    ans += sum(f) == 4
print(ans)