t = int(input())
for _ in range(t):
    a = list(input())
    b = list(input())
    
    i = 0
    while i < min(len(a), len(b)) and a[i] == b[i]:
        i += 1
        
    if i > 1:
        print(len(a) + len(b) - i + 1)
    else:
        print(len(a) + len(b))
        
    
    
    
    