def solve():
    r, c = map(int, input().split())
    r, c = abs(r), abs(c)
    if r < c: r, c = c, r 
    
    if r == c: return r * 2
    return r * 2 - 1


t = int(input())
for _ in range(t):
    print(solve())
