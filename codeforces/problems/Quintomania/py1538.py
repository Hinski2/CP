t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    for a, b in zip(v, v[1:]):
        if abs(a - b) != 5 and abs(a - b) != 7:
            print('NO')
            break
    else:
        print('YES')
    