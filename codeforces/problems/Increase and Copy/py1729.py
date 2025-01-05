from math import sqrt, ceil
t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print(0)
        continue
    
    x = ceil(sqrt(n)) 
    print(x - 1 + ceil(n / x) - 1)
    
