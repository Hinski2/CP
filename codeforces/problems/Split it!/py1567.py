t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = list(input())
    if 2*k + 1 > n:
        print('NO')
    elif k == 0 or s[:k] + s[-k:] == list(reversed(s[:k] + s[-k:])):
        print('YES')
    else:
        print('NO')
         