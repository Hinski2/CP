t = int(input())
for _ in range(t):
    n = int(input())
    s = input()

    ans = 0
    for i in range(n):
        if s[i] == '@': ans += 1
        elif i + 1 < n and s[i] == '*' and s[i + 1] == '*':
            break
    print(ans)