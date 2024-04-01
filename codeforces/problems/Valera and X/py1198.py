n = int(input())
s = [input() for _ in range(n)]

diag = s[0][0]
diff = s[0][1]
ans = diag != diff
for i in range(n):
    if s[i][i] != diag: ans = False
for i in range(n):
    if s[i][n - 1 - i] != diag: ans = False

for i in range(n):
    for j in range(n):
        if i == j or i == n - 1 - j: continue
        if s[i][j] != diff: ans = False

if ans:
    print("YES")
else:
    print("NO")
    