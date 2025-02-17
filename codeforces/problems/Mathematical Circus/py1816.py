# we need (a + k) * b =_4 0
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    k = k % 4
    if k == 0:
        print("NO")
        
    elif k == 2:
        print('YES')
        
        np = list(range(1, n + 1, 2)) 
        p = list(range(2, n + 1, 2)) 
        
        for u, w in zip(np, p):
            if w % 4 == 0:
                print(u, w)
            else:
                print(w, u)
        
    else:
        print('YES')
   
        np = list(range(1, n + 1, 2)) 
        p = list(range(2, n + 1, 2)) 
    
        for u, w in zip(np, p):
            print(u, w)
        
         