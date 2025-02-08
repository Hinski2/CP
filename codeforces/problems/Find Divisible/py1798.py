t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    
    for i in range(l, r + 1):
        if l * 2 <= r:
            print(l, 2*l)
            break 