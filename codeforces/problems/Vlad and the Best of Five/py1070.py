t = int(input())
while t:
    s = input()

    a, b = 0, 0
    for i in s:
        if i == 'A':
            a += 1
        else:
            b += 1
    
    if a > b:
        print('A')
    else:
        print('B')
    t -= 1

