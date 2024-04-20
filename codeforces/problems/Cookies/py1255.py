n = int(input())
v = list(map(int, input().split()))

s, ans = sum(v), 0
for u in v:
    if (s - u) % 2 == 0: ans += 1
    
print(ans)
    