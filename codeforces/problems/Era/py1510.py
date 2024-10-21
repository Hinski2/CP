t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    maxi = 0
    for i in range(n):
        maxi = max(maxi, v[i] - (i + 1))
    
    print(maxi)