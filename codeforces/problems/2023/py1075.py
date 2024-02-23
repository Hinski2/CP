t = int(input())
while t:
    t -= 1
    b_size, deleted = map(int, input().split())
    b = map(int, input().split())

    product = 1
    bad = False
    for i in b:
        product *= i
        if 2023 % i != 0:
            bad = True
    if bad or 2023 % product != 0:
        print("NO")
        continue
    
    a = [int(2023 / product)] + [1 for i in range(deleted - 1)]
    print("YES")
    print(*a)

    