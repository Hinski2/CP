t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    ans = 1
    while a or b: 
        if a % 2 == b % 2: ans *= 2
        else: break
        a //= 2; b //= 2
    print(ans)
    