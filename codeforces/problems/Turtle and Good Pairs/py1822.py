t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input())
    alf = [0] * (ord('z') + 1)
    for u in s:
        alf[ord(u)] += 1
        
    ok = True
    ans = []
    while ok:
        ok = False
        for i in range(ord('a'), ord('z') + 1):
            if alf[i]:
                ok = True
                ans.append(chr(i))
                alf[i] -= 1 
    print(''.join(ans))
        