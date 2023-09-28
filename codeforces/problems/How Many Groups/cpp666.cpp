#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second;
 
int n, cnt;
vector<vector<int>> G;
vector<int>occ, ans, group;
 
void dfs(int v){
    occ[group[v]]++;
    if(occ[group[v]] == 1) cnt++;
    ans[v] = cnt;
    for(auto u: G[v])
        dfs(u);
    occ[group[v]]--;
    if(occ[group[v]] == 0) cnt--;
}
 
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    G.resize(n + 1), occ.resize(n + 1), ans.resize(n + 1), group.resize(n + 1);
    for(int i = 1, x; i <= n; i++){
        cin >> x;
         G[x].push_back(i);
    }
 
    for(int i = 1; i <= n; i++)
        cin >> group[i];
    dfs(G[0][0]);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}