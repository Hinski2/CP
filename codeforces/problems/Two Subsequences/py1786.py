t = int(input())
for _ in range(t):
    s = input()
    
    for c in range(ord('a'), ord('z') + 1):
        if chr(c) in s:
            a = chr(c)
            break 
    
    skipped = False
    b = []
    for u in s:
        if skipped == False and u == a:
            skipped = True
        else:
            b.append(u)
            
    print(a, ''.join(b))