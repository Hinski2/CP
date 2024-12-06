t = int(input())
ans = [] 
for _ in range(t):
    n, m = map(int, input().split())
    ss = [input() for _ in range(n)]
    place = 0; x = 0
    for i in range(n):
        if place + len(ss[i]) <= m: 
            x += 1
            place += len(ss[i])
        else:
            break 
    ans.append(x)
print(*ans, sep='\n')