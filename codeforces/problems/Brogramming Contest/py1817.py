t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input())
    let = '0'
    ans = 0
    
    for u in s:
        if u != let:
            ans += 1
        let = u 
        
    print(ans)