from math import sqrt
def find_div(x):
    div = [] 
    for i in range(1, int(sqrt(x)) + 2):
        if x % i == 0:
            div.append(i) 
            div.append(x // i)
    return div
        
t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    
    if all(u == v[0] for u in v):
        print(-1)
        continue
    
    m = min(v)
    v = [u - m for u in v]
    
    div_list = [find_div(i) for i in v]
    maxi = -1
    
    dif = set()
    for u in div_list:
        for w in u:
            dif.add(w)
            
    for u in dif:
        if all(u in div_list[i] or not v[i] for i in range(0, len(div_list))):
            maxi = max(maxi, u)
    print(maxi)