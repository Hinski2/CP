t = int(input())
for _ in range(t):
    w, h = map(int, input().split())
    v = [list(map(int, input().split()))[1:] for _ in range(4)]
    
    ans = 0 
    for i in range(4):
        ans = max(ans, (v[i][-1] - v[i][0]) * (h if i < 2 else w))
    print(ans)
    