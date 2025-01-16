def f(x):
    ans, y = 0, x
    while y % 2 == x % 2:
        ans += 1
        y //= 2
    return ans 

t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(x) for x in input().split()]
    if sum(v) % 2 == 0:
        print(0)
        continue
    else: 
        print(min(map(f, v)))