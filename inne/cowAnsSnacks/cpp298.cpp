//nick na codeforces: Hinski2
//link do profilu: https://codeforces.com/profile/Hinski2
//link do zgłoszenia: https://codeforces.com/contest/1209/submission/186819326

#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m;
int ans, cnt;

vector<bool>vis;
vector<vector<int>>add;

inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

    vis.resize(n + 1);
    add.resize(n + 1);

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        add[a].push_back(b);
        add[b].push_back(a);
    }
}

void dfs(int v){
    vis[v] = 1;
    cnt++;

    for(auto u: add[v])
        if(!vis[u])
            dfs(u);
}


int main(){
	wczytaj();

    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            cnt = 0;
            dfs(i);
            ans += cnt - 1;
        }

    cout << m - ans << '\n';
}
