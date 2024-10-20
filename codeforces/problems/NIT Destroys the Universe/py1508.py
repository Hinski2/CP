t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    
    ans, numb = 0, False 
    for i in range(n):
        if v[i]: numb = True
        if v[i] == 0 and numb:
            numb = False
            ans += 1
    if numb:
        ans += 1
        
    print(min(ans, 2))