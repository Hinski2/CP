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

ll solve(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    map<int, int> mapa;
    for(auto u: v) mapa[u]++;

    priority_queue<pii> pq;
    for(auto [a, b]: mapa) pq.push({b, a});

    int sajz = n;
    while(pq.size() >= 2){
        pii v1 = pq.top(); pq.pop();
        pii v2 = pq.top(); pq.pop();
        v1.fi--, v2.fi--, sajz -= 2;
        if(v1.fi) pq.push(v1);
        if(v2.fi) pq.push(v2);
    }

    return sajz;
}

int main(){
    io; int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
