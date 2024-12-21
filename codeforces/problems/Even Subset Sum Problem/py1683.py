t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    even = [i + 1 for i in range(0, n) if v[i] % 2 == 0]
    odd = [i + 1 for i in range(0, n) if v[i] % 2 == 1]
    if even:
        print(1)
        print(even[0])
    elif len(odd) > 1:
        print(2)
        print(*odd[:2])
    else:
        print(-1)
   