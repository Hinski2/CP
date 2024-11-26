t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    v = [0] + [int(i) for i in input().split()][::-1]
    a, idx = 0, 1
    while idx < n:
        if v[idx + 1] != v[1]:
            a += 1
            idx *= 2
        else:
            idx += 1
    ans.append(a)
        
print(*ans, sep='\n') 
    
    