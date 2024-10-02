t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    
    num: list[list[int]] = [[],[]]
    for i in range(n):
        num[v[i] % 2].append(i + 1)
    
    if len(num[1]) >= 3:
        print("YES")
        print(*num[1][:3])
    elif len(num[1]) >= 1 and len(num[0]) >= 2:
        print("YES")
        print(*num[0][:2], num[1][0])
    else:
        print("NO")
        