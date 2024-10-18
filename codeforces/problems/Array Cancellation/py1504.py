t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    acc = 0
    for i in range(len(v)):
        if v[i] > 0: 
            acc += v[i]
            v[i] = 0
        else:
            x = min(abs(v[i]), acc)
            acc -= x 
            v[i] += x 
        
    print(acc)