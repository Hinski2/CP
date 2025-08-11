t = int(input())

def f(pos) -> int:
    if pos in [[1, 1], [1, m], [n, 1], [n, m]]:
        return 2
    elif pos[0] in [1, n] or pos[1] in [1, m]:
        return 3
    else:
        return 4

for _ in range(t):
    n, m = map(int, input().split())
    i = list(map(int, input().split()))
    a, b = i[:2], i[2:]
    ans = min(f(a), f(b))
    print(ans)