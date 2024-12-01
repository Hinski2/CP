n, v1, v2, p1, p2 = map(int, input().split())
t1 = 2 * p1 + n * v1 
t2 = 2 * p2 + n * v2 
if t1 < t2:
    print('First')
elif t1 > t2:
    print('Second')
else:
    print('Friendship')