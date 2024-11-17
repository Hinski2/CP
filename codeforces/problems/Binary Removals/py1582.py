t = int(input())
ans = []
for _ in range(t):
    v = [int(i) for i in list(input())]
    v = zip(v[:], v[1:])
    one = 0
    for u in v:
        if u == (1, 1):
            one = True
        if u == (0, 0) and one: 
            ans.append('NO')
            break
    else: 
        ans.append('YES')
print(*ans, sep='\n')
    