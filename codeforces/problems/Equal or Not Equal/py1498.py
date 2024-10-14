t = int(input())
for _ in range(t):
    s = input()
    n = 0
    for u in s:
        n += (u == 'N')
    
    if n == 1: print("NO")
    else: print("YES")
    