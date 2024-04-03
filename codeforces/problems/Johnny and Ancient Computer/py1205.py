def r(x):
    while x % 2 == 0:
        x //= 2
    return x

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if a > b: a, b = b, a
    
    if r(a) != r(b):
        print(-1)
        continue
    
    ans = 0
    b //= a
    
    while b >= 8:
        b //= 8
        ans += 1
    
    if b > 1:
        ans += 1
    
    print(ans)
    
    