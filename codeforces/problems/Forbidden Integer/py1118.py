t = int(input())
for _ in range(t):
    n, k, x = map(int, input().split())

    if x == 1 and k == 2 and n % 2 == 1:
        print("NO")
    elif k == 1 and x == 1:
        print("NO")
    elif x == 1:
        print("YES")
        v = []
        if n % 2 == 1: 
            v.append(3)
            n -= 3
        for i in range(n // 2):
            v.append(2)
        print(len(v))
        print(*v, sep=' ')
    else:
        print("YES")
        v = [1] * n
        print(n)
        print(*v, sep=' ')