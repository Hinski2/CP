t = int(input())
for _ in range(t):
    n = int(input())
    a, b = set(), set()
    for i in map(int, input().split()):
        a.add(i)
    for i in map(int, input().split()):
        b.add(i)
        
    if len(a) + len(b) >= 4:
        print('YES')
    else:
        print('NO')