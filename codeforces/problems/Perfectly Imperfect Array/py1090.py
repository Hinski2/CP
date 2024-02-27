from math import sqrt
t = int(input())
for _ in range(t):
    n = int(input())
    v = map(int, input().split())

    ans = False
    for i in v:
        if int(sqrt(i)) * int(sqrt(i)) != i: ans = True
    
    if ans: print("YES")
    else: print("NO")
            