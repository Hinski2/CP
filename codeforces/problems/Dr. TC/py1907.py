t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    ans = 0
    for c in s:
        if c == '0': ans += 1
        else: ans += n - 1 
    print(ans)