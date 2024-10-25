t = int(input())
ans = [] 
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    ans.append(v[::-1])
for u in ans:
    print(*u)
    