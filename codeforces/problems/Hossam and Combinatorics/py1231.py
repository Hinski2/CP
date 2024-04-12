t = int(input())
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    low, hi = min(v), max(v)
    if low == hi:
        print(n * (n - 1))
    else:
        print(2 * v.count(low) * v.count(hi))
    
