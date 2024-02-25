t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))

    find_minus = False
    for u in v:
        if u == -1: find_minus = True

    find_2_minus = False
    for i in range(0, len(v) - 1):
        if v[i] == v[i + 1] == -1: find_2_minus = True
    
    ans = sum(v)
    if find_2_minus:
        ans += 4
    elif find_minus:
        ans
    else:
        ans -= 4

    print(ans)
    