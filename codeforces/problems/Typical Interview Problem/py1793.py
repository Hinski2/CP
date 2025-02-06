a = []
for i in range(1, 50):
    if i % 3 == 0: a.append('F')
    if i % 5 == 0: a.append('B')
fb = ''.join(a)

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    
    if s in fb:
        print('YES')
    else:
        print('NO')
        