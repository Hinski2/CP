t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    plus, minus = v.count(1), v.count(-1)
    ans = 0; s = sum(v)
    if s < 0:
        plus -= s // 2
        minus += s // 2
        ans -= s // 2
    
    if minus % 2:
        ans += 1
    print(ans)
    