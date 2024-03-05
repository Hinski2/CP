t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    a = map(int, input().split())
    b = map(int, input().split())

    cnt = [0 for _ in range(k + 1)]
    for i in a:
        if i <= k: cnt[i] |= 1
    for i in b:
        if i <= k: cnt[i] |= 2

    v = [0] * 4
    for i in range(1, len(cnt)):
        v[cnt[i]] += 1
    
    if v[0] or v[1] > k // 2 or v[2] > k // 2:
        print("NO")
    else:
        print("YES")

    




