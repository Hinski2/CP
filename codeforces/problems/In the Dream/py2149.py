t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    if a > c or b > d: print("NO"); continue
 
    c -= a
    d -= b
 
    if (a + 1) * 2 < b: print("NO")
    elif (b + 1) * 2 < a: print("NO")
    elif (c + 1) * 2 < d: print("NO")
    elif (d + 1) * 2 < c: print("NO")
    else: print("YES")