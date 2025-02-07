x, y, z = map(int, input().split())
a, b, c = map(int, input().split())

for i in range(1):
    if x > a:
        print('NO')
        continue
    a -= x 
    
    if y > a + b:
        print('NO')
        continue
    a -= y 
    if z > a + b + c:
        print('NO')
    else:
        print('YES')




