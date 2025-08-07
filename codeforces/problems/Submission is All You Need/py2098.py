t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(u) for u in input().split()]
    
    while 0 in v:
        x = 0
        while x in v and x < 2:
            v.remove(x)
            x += 1
            
        v.append(x)
    print(sum(v))
