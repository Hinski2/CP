t = int(input())
for _ in range(t):
    n = int(input())
    if n & 1:
        print(7, end="")
        n -= 3
    while n:
        print(1, end="")
        n -= 2
    print()
    
        