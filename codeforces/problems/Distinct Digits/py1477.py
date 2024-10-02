def check(x:int):
    num = [0 for _ in range(10)]
    while x: 
        if num[x % 10]:
            return 0
        num[x % 10] = 1
        x //= 10 
    return 1

l, r = map(int, input().split())
for x in range(l, r + 1):
    if check(x):
        print(x)
        break
else:
    print(-1)