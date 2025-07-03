t = int(input())
alice = "Alice"
bob = "Bob"
for _ in range(t):
    n = int(input())
    if n % 4 == 0:
        print(bob)
    else:
        print(alice) 
