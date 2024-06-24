from math import gcd
t = int(input())
for _ in range(t):
    x = int(input())
    maxi = 1
    for i in range(1, x):
        if gcd(maxi, x) + maxi < gcd(i, x) + i:
            maxi = i 
    print(i)
