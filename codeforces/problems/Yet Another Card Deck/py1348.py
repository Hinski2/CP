t = int(input())
for _ in range(t):
    n = int(input())
    if n == 2 or n & 1:
        print(-1)
        continue
    
    n //= 2
    mini = (n + 2) // 3
    maxi = n // 2
    print(mini, maxi)

    
   
        