t = int(input())
for _ in range(t):
    n = int(input())
    v = input()
    l = [0, 0]
    for i in v:
        if i == 'L': l[0] += 1
        else: l[1] += 1
    
    if l[0] == 0 or l[1] == 0:
        print(-1)
        continue

    fr = v.find('R')
    fl = v.find('L', fr)

    if(fl != -1 and fr != -1):
        print(0)
    else:
        p = v.find("LR")
        print(p + 1)

