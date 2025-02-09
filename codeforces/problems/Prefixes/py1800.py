n = int(input())
s = list(input())
ans = 0
for i in range(0, n, 2):
    if s[i] == s[i + 1]:
        s[i], s[i + 1] = 'a', 'b'
        ans += 1
print(ans)
print(*s, sep='')
