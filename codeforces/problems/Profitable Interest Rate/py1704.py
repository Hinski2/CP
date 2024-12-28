t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if a >= b:
        print(a)
    else:
        x = b - a 
        a -= x 
        print(max(0, a))