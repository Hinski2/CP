t = int(input())
for _ in range(t):
    n, a, b, c = map(int, input().split())
    suma = a + b + c
    ile = n // suma
    n -= ile * suma 
    ile *= 3
   
    if n == 0:
        print(ile)
    elif n <= a:
        print(ile + 1)
    elif n <= a + b:
        print(ile + 2)
    else:
        print(ile + 3)
    