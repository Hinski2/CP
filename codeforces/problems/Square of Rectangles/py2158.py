def solve():
    inp = [int(i) for i in input().split()]
    l, b = inp[::2], inp[1::2]
    
    if sum(l) == b[0] == b[1] == b[2]:
        return "YES"
    if sum(b) == l[0] == l[1] == l[2]:
        return "YES"
    if l[0] + l[1] == l[0] + l[2] == b[0] == b[1] + b[2]:
        return "YES"
    if b[0] + b[1] == b[0] + b[2] == l[0] == l[1] + l[2]:
        return "YES"
    
    return "NO" 
    

t = int(input())
for _ in range(t):
    print(solve())
