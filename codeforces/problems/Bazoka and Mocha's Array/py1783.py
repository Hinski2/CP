t = int(input())
for _ in range(t):
    n = int(input())
    vs = [int(i) for i in input().split()]
    
    if all(a <= b for a, b in zip(vs[0:], vs[1:])):
        print('YES')
        continue
    
    idx = 0
    for i in range(1, n):
        if vs[i - 1] > vs[i]:
            idx = i 
            break 
            
    l = list(vs[idx:]) + list(vs[0: idx])
    if all(a <= b for a, b in zip(l[0:], l[1:])):
        print('YES')
    else:
        print('NO')