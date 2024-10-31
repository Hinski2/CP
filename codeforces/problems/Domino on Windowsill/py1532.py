t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    white, black = map(int, input().split())
    wp = a + b 
    bp = n - a + n - b
    if white <= wp // 2 and black <= bp // 2:
        print("YES")
    else:
        print("NO")