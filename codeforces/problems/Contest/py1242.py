p1, p2, t1, t2 = map(int, input().split())
p1 = max(75 * p1, 250 * p1 - p1 * t1)
p2 = max(75 * p2, 250 * p2 - p2 * t2)

if p1 == p2:
    print('Tie')
else:
    print('Misha' if p1 > p2 else 'Vasya')