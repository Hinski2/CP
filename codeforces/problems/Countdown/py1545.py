def non_zero(v):
    ans = 0
    for u in v:
        if u != 0: ans += 1
    return ans - (v[-1] != 0)

t = int(input())
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input()]
    ans = 0
    print(non_zero(v) + sum(v))