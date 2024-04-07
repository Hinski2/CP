t = int(input())
for _ in range(t):
    n = int(input())
    v = map(int, input().split())
    ans = 2022
    mult = 1
    for u in v:
        mult *= u
    mult += n - 1
    ans *= mult
    print(ans)