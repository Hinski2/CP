#include <bits/stdc++.h>
using namespace std;

int n, k;
int G[500005];
vector <int> G2[500005]; // odwrócony graf

int cycle_size[500005];
int id;

int cycle_id[500005];
int ord[500005]; // kolejność w cyklu

int depth[500005];
int P[500005];

int color[500005];
int cur[500005];
void dfs(int v) {
    color[v]++;
    cur[v]++;
    
    if(color[v] == 2) {
        cycle_id[v] = id;
        ord[v] = cycle_size[id]++;
    }
    
    int u = G[v];
    if(color[u] == 0 || (color[u] == 1 && cur[u])) dfs(u);
    
    
    cur[v]--;
}

void find_cycles() {
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            id++;
            dfs(i);
        }
    }
}

int l[500005][20];

void build_lca() {
    for(int i = 1; i <= n; i++)
        l[i][0] = P[i];
    
    for(int i = 1; i < 20; i++) {
        for(int v = 1; v <= n; v++)
            l[v][i] = l[l[v][i - 1]][i - 1];
    }
}

int root[500005];

void dfs2(int v, int p, int r) {
    root[v] = r;
    for(auto u: G2[v]) if(u != p && cycle_id[u] == 0) {
        depth[u] = depth[v] + 1;
        dfs2(u, v, r);
        P[u] = v;
    }
}

void find_depth() {
    for(int i = 1; i <= n; i++) {
        if(cycle_id[i] != 0) {
            dfs2(i, -1, i);
        }
    }
}

int lca(int p, int q) {
    if(depth[p] < depth[q]) swap(p, q);
    
    for(int i = 20; i >= 0; i--) {
        if(depth[p] - (1 << i) >= depth[q]) {
            p = l[p][i];
        }
    }
    
    if(p == q) return p;
    
    for(int i = 20; i >= 0; i--) {
        if(l[p][i] != l[q][i]) {
            p = l[p][i];
            q = l[q][i];
        }
    }
    return l[p][0];
}

pair <int, int> minp(pair <int, int> a, pair <int, int> b) {
    if(max(a.first, a.second) < max(b.first, b.second)) return a;
    if(max(a.first, a.second) == max(b.first, b.second) && min(a.first, a.second) < min(b.first, b.second)) return a;
    if(max(a.first, a.second) == max(b.first, b.second) && min(a.first, a.second) == min(b.first, b.second) && a.second < b.second) return a;
    return b;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        G[i] = a;
        G2[a].push_back(i);
    }
    
    find_cycles();
    
    find_depth();
    
    build_lca();
    
    while(k--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(root[x] == root[y]) { // to samo drzewo
            int LCA = lca(x, y);
            printf("%d %d\n", depth[x] - depth[LCA], depth[y] - depth[LCA]);
        } else {
            int r_x = root[x];
            int r_y = root[y];
            if(cycle_id[r_x] != cycle_id[r_y]) {
                printf("-1 -1\n");
            } else {
                int dx, dy;
                if(ord[r_x] < ord[r_y]) {
                    dx = ord[r_y] - ord[r_x];
                    dy = cycle_size[cycle_id[r_x]] - (ord[r_y] - ord[r_x]);
                } else {
                    dy = ord[r_x] - ord[r_y];
                    dx = cycle_size[cycle_id[r_x]] - (ord[r_x] - ord[r_y]);
                    
                }
                pair <int, int> res1 = minp({depth[x] + dx, depth[y]}, {depth[x], depth[y] + dy});
                printf("%d %d\n", res1.first, res1.second);
            }
        }
    }
}