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

inline bool equal(vector<int> &v){
    int a = v[0];
    for(auto u: v)
        if(u != a) return 0;
    return 1;
}

bool check(vector<int> v){
    if(equal(v)) return 1;
    if(v.size() >= 6) return 0;

    for(int i = 0; i < v.size() - 1; i++){
        int a = v.back() - v[i];
        int b = v.back() - a;

        vector<int> w = v;
        w.pop_back();
        w.pb(a);
        w.pb(b);
        if(!a || !b) continue;

        sort(all(w));
        if(check(w)) return 1;
    }

    return 0;
}

int solve(){
    vector<int> v(3); cin >> v;
    sort(all(v));
    if(equal(v)) return 1;
    return check(v);
}

int main(){
    io; int t; cin >> t;
    while(t--)
        cout << yn << endl;
}
