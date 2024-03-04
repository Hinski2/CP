t = int(input())
for _ in range(t):
    zero = False
    minus = 0
    n = int(input())
    v = list(map(int, input().split()))

    idx = 0
    for i in range(len(v)):
        if v[i] == 0: zero = True
        if v[i] < 0: 
            minus += 1
            idx = i
    
    if minus & 1:
        print(0)
    elif zero:
        print(0)
    else:
        print(1)
        print(1, 0)