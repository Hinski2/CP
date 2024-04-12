t = int(input())
for _ in range(t):
    n = int(input())
    a, b = map(int, input().split())
    ans = True
    for i in range(n - 1):
        x, y = map(int, input().split())
        if x >= a and y >= b: ans = False
    
    print(a if ans else -1)
    