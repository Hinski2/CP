from math import sqrt

t = int(input())
for _ in range(t):
    n = int(input())
    s = sum(range(1, n + 1))
    if int(sqrt(s)) * int(sqrt(s)) == s:
        print(-1)
    else:
        suma, i = 0, 1
        while i <= n:
            if int(sqrt(suma + i)) * int(sqrt(suma + i)) == suma + i:
                print(i + 1, i, end=' ')
                suma += i + i + 1
                i += 2 
            else:
                print(i, end= ' ')
                suma += i
                i += 1
        print()
             