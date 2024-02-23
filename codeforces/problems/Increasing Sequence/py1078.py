t = int(input())
for _ in range(t):
    n = int(input())
    v = map(int, input().split())
    
    ans = 1
    for i in v:
        if ans == i: ans += 1
        ans += 1
    print(ans - 1)