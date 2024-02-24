for _ in range(int(input())):
    n = int(input())
    v = sorted(list(map(int, input().split())))

    ans = 0
    for i in range(1, n):
        ans += v[i] - v[i - 1]
    
    print(ans)