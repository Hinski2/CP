t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    x = d if d != a else d - 1 
    print(a, x)