t = int(input())
for _ in range(t):
    l, r, a, b = map(int, input().split())
    if max(l, a) <= r and max(l, a) <= b: 
        print(max(l, a))
    else:
        print(l + a)