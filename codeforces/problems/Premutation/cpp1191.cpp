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

void solve(){
    int n; cin >> n; 
    vector<vector<int>> v(n + 1);
    vector<int> in(n + 1);

    for(int i = 0, x; i < n; i++){
        vector<int> vec(n - 1); cin >> vec;
        for(int j = 0; j < n - 2; j++){
            v[vec[j]].pb(vec[j + 1]);
            in[vec[j + 1]]++;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(in[i] == 0) q.push(i);

    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int a = q.front();
        ans[i] = a;
        q.pop();

        for(auto u: v[a]){
            in[u]--;
            if(!in[u]) q.push(u);
        }
    }
    
    cout << ans << endl;
}

int main(){
    io; int t; cin >> t;
    while(t--)
        solve();
}
