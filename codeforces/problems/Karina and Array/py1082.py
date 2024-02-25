t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))

    ans1, ans2 = 0, 0
    m1, m2 = -(1e9 + 7), -(1e9 + 7)
    for i in v:
        if i >= m1:
            m2 = m1
            m1 = i
        elif i >= m2:
            m2 = i
    ans1 = m1 * m2
    m1, m2 = 1e9, 1e9
    for i in v:
        if i <= m1:
            m2 = m1
            m1 = i
        elif i <= m2:
            m2 = i
    ans2 = m1 * m2
    print(max(ans1, ans2))  