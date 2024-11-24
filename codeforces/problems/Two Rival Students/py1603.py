t = int(input())
for _ in range(t):
    n, x, a, b = map(int, input().split())
    if a > b: a, b = b, a 
    dist = a - 1 + n - b 
    print(b - a + min(x, dist))