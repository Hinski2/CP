def solve(n, k):
    if n % 2 == 0: return 'YES'
    if k % 2 == 1 and (n - k) >= 0: return 'YES'
    return 'NO'


t = int(input())
while t:
    t -= 1
    a, b = map(int, input().split())
    print(solve(a, b))