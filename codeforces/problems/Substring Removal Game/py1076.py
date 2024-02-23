t = int(input())
for _ in range(t):
    s = input()
    l = []

    cnt = 0
    for i in s:
        if i == '1': cnt += 1
        if i == '0' and cnt:
            l.append(cnt)
            cnt = 0
    if cnt:
        l.append(cnt)
    l.sort(reverse=True)
    print(sum(l[::2]))
