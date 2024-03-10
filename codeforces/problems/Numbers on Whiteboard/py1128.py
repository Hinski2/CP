t = int(input())
for _ in range(t):
    n = int(input())
    print(2)
    v = []
    if n == 2:
        print(1, 2)
        continue
        
    print(n - 2, n)
    v = [i for i in range(1, n - 2)] + [n - 1, n - 1]
    while len(v) > 1:
        a, b = v[-1], v[-2]
        print(a, b)
        
        v.pop()
        v.pop()
        v.append((a + b) // 2)
        
        
        
        
        
            