t = int(input())
for i in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    
    maxi = 0 
    for i in range(n + 1):
        maxi = max(v.count(i), maxi)
    
    print(n - maxi) 
        
        