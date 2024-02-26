import math
t = int(input())
for _ in range(t):
    a, b = map(int , input().split())
    s = a ** 2 + b ** 2
    if s == 0: print(0)
    elif int(math.sqrt(s)) * int(math.sqrt(s)) == s: print(1)
    else: print(2)



