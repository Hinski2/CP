t = int(input())
for _ in range(t):
    v = [ord(i) - ord('0') for i in input()]
    for i in range(len(v) - 2, -1, -1):
        if v[i] + v[i + 1] >= 10:
            v[i + 1] += v[i] - 10
            v[i] = 1
            break
    else:
        v[1] += v[0]
        v.pop(0)
        
    print(*v, sep='')
        
    