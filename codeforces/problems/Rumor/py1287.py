n, m = map(int, input().split())
cost = [0] + list(map(int, input().split()))
G = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y = map(int, input().split())
    G[x].append(y)
    G[y].append(x)

vis = [0] * (n + 1)
def dfs(v):
    vis[v] = True
    mini = cost[v]
    for u in G[v]:
        if not vis[u]: mini = min(mini, dfs(u))
    
    return mini

ans = 0
for v in range(1, n + 1):
    if not vis[v]:
        ans += dfs(v)

print(ans)
        
    