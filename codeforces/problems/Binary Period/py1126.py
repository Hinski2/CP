t = int(input())
for _ in range(t):
    s = input()
    same = True
    sameD = s[0]
    for i in s:
        if i != sameD: same = False
    if same:
        print(s)
    else:
        v = [i % 2 for i in range(2 * len(s))]
        print(''.join(map(str, v)))