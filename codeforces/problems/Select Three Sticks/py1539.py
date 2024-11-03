def cost(a, b, c):
    return b - a + c - b
    
t = int(input())
for _ in range(t):
    n = int(input())
    v = sorted([int(i) for i in input().split()])
    ans = float('inf')
    for a, b, c in zip(v[:], v[1:], v[2:]):
        ans = min(ans, cost(a, b, c))
    print(ans)
        