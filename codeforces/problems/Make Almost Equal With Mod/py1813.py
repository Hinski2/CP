t = int(input())
for _ in range(t):
    n = int(input())
    vs = list(map(int, input().split()))
    if all([v % 2 == 0 for v in vs]) or all([v % 2 == 1 for v in vs]):
        ans = 2
        while len(set([v % ans for v in vs])) != 2:
            ans *= 2
        print(ans)
    else:
        print(2)