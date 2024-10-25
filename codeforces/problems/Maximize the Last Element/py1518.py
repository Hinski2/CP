t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    ans.append(max(v[::2]))
for u in ans:
    print(u, end='\n')