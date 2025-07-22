t = int(input())
for _ in range(t):
    l, r, x = map(int, input().split())
    a, b = map(int, input().split())
    if a > b: a, b = b, a
    
    if a == b:
        print(0)
    elif abs(a - b) >= x:
        print(1)
    elif abs(r - b) >= x or abs(l - a) >= x:
        print(2)
    elif (abs(b - l) >= x and abs(r - a) >= x) or (abs(a - r) >= x and abs(b - l) >= x):
        print(3)
    else:
        print(-1)
