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

int t;
map<char, pii> mapa; 

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

bool solve(){
    int n; cin >> n;
    pii pos = {0, 0};
    bool ans = false;
    string s;
    cin >> s;
    for(auto u: s){
        pos.fi += mapa[u].fi;
        pos.se += mapa[u].se;
        if(pos.fi == 1 && pos.se == 1) ans = true;
    }

    return ans;
}
int main(){
    get_input();
    mapa['L'] = {-1, 0};
    mapa['R'] = {1, 0};
    mapa['U'] = {0, 1};
    mapa['D'] = {0, -1};
    while(t--)
        cout << (solve() ? "YES" : "NO") << endl;
}
