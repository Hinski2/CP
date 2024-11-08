t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = [0] + [int(i) for i in input().split()]
    for i in range(1, n + 1):
       a[i%k] = max(a[i%k], a[i]) 
    print(sum(a[:k])) 
        
    
    