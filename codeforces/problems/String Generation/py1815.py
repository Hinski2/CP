t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    ans = ['a', 'b', 'c'] * (n // 3)
    if n % 3 == 1:
        ans += 'a'
    elif n % 3 == 2:
        ans += ['a', 'b']
    print(''.join(ans))