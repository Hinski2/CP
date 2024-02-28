t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))

    ans = 0
    for i in range(n-2, -1, -1):
        while v[i] and v[i] >= v[i + 1]:
            v[i] //= 2
            ans += 1
            
        if v[i] == v[i + 1]:
            ans = -1
            break
    print(ans)

