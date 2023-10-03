#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1

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

ll n, m, len;
vector<vector<pll>> G, G2;
vector<vector<ll>> odl(2);
vector<ll> skad;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    G.resize(n + 1), G2.resize(n + 1), odl[0].resize(n + 1), odl[1].resize(n + 1), skad.resize(n + 1);
    for(int i = 0, a, b, w; i < m; i++){
        cin >> a >> b >> w;
        G[a].pb({b, -w});
        G[b].pb({a, -w});
    }
}

void dijkstra(int from, int to, int opt){
    priority_queue<pair<pair<ll, ll>, int>>pq;
    pq.push({{0, from}, 0});
    while(!pq.empty()){
        int v = pq.top().fi.se;
        int w = pq.top().fi.fi;
        int s = pq.top().se;

        pq.pop();
        if(odl[opt][v]) continue;
        odl[opt][v] = -w;
        skad[v] = s;

        for(auto u: G[v])
            if(!odl[opt][u.fi]){
                    pq.push({{u.se + w, u.fi}, v});
                if(opt == 0) G2[v].pb(u);
            }
    }
}

vector<int> ans;
void odzyskaj(int v){
    ans.pb(v);
    if(v != 1) odzyskaj(skad[v]);
}

int main(){
    get_input();
    dijkstra(1, n, 0);
    odl[0][1] = 0, odl[1][n] = 0;
    len = odl[0][n];
    if(len == 0){
        cout << "-1" << endl;
        return 0;
    }

    odzyskaj(n);
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
    cout << endl;
}
