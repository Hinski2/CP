t = int(input())
for _ in range(t):
    n = int(input())

    if n < 100:
        print(n % 10)
    else:
        smallest = 10
        while n:
            smallest = min(smallest, n % 10)
            n //= 10
        print(smallest)
        