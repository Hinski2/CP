def solve():
    n = int(input())
    v = [int(i) for i in input().split()]
    if (0, 0) in zip(v[:], v[1:]):
        return -1
    
    size = int(v[0] > 0) + 1
    for i in range(1, n):
        if v[i] > 0 and v[i - 1] > 0:
            size += 5
        elif v[i] > 0:
            size += 1
    return size
     
t = int(input())
for _ in range(t):
    print(solve())
