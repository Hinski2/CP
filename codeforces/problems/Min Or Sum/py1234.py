t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    

    orr = 0
    for u in v:
        orr |= u 

    print(orr)

