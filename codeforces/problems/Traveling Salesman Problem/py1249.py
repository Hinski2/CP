t = int(input())
for _ in range(t):
    n = int(input())
    minX, minY, maxX, maxY = 0, 0, 0, 0
    for _ in range(n):
        a, b = map(int, input().split())
        minX = min(minX, a)
        maxX = max(maxX, a)
        minY = min(minY, b)
        maxY = max(maxY, b)
    
    print(2 * (maxX - minX + maxY - minY))
    

