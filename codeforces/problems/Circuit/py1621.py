t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    
    on = sum(v)
    maxi = on if on <= n else 2 * n - on
    mini = 1 if on % 2 else 0 
    print(mini, maxi)