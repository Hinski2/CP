from math import gcd
t = int(input())
ans = [0] * t
for i in range(t):
    a, b, c, d = map(int, input().split())
    x, y = a * d, b * c
    
    if x == y: ans[i] = 0
    elif y and not x % y or x and not y % x: ans[i] = 1
    else: ans[i] = 2
    
print(*ans, sep='\n')