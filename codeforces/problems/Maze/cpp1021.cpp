#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& u : v){
        is >> u;
    }
    return is;
}

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define yn (solve() ? "YES" : "NO")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tree<int,null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
//erase: oms.erase(oms.upper_bound(value))

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

int n, m, k, cnt;
vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pii> vec = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool ok(pii x){
    if(!vis[x.fi][x.se] && grid[x.fi][x.se] == '.') return 1;
    return 0;
}

void dfs(pii x){
    vis[x.fi][x.se] = 1;
    int neigh = 0;
    for(auto u: vec){
        pii new_x = {x.fi + u.fi, x.se + u.se};
        if(ok(new_x)){
            neigh++;
            dfs(new_x);
            if(grid[new_x.fi][new_x.se] == 'X') neigh--;
        }
    }

    if(cnt < k && !neigh){
        grid[x.fi][x.se] = 'X';
        cnt++;
    }
}

int main(){
    io; cin >> n >> m >> k;
    grid.resize(n + 2);
    vis.resize(n + 2);
    for(int i = 0; i < n + 2; i++)
        grid[i].resize(m + 2, '#'), vis[i].resize(m + 2);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(ok({i, j})){
                dfs({i, j});
                break;
            }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << grid[i][j];
        cout << endl;
    }

}
