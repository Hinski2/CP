t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    s = sum(v)
    
    a = s % n
    a = a * (n - a)
    print(a)
    