t = int(input())
for _ in range(t):
    x, y, k = map(int, input().split())
    while k > 0 and x != 1:
        nk = min(k, max(1, (x // y + 1) * y - x))
        x += nk 
        k -= nk
        
        while x % y == 0:
            x //= y 
    print(x + k % (y - 1))
        
        
