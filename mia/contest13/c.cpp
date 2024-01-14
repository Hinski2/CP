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

ll n, q;
vector<ll> v;
vector<ll> c;

struct zap{
    ll fi;
    ll se;
    ll idx;
};

ll brut(ll a, ll b){
    ll sum = 0;
    for(ll i = a; i <= n; i += b)
        sum += v[i];
    
    return sum;
}

void make_c(ll x){
    for(int i = n; i >= n - x; i--)
        c[i] = v[i];
    for(int i = n - x; i > 0; i--)
        c[i] = v[i] + c[i + x];
}

ll clever(ll a, ll b){
    return c[a];
}

bool cmp(zap a, zap b){
    if(a.se != b.se) return a.se < b.se;
    return a.fi < b.fi;
}

int main(){
    io; cin >> n;
    v.resize(n + 1);
    c.reserve(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    cin >> q;
    vector<zap> pq(q);
    for(int i = 0; i < q; i++){
        cin >> pq[i].fi >> pq[i].se;
        pq[i].idx = i;
    }

    sort(all(pq), cmp);
    vector<ll> ans(q);

    int last = 0;
    for(auto u: pq){
        if(u.se < sqrt(n)){
            if(u.se != last) make_c(u.se);
            ans[u.idx] = clever(u.fi, u.se);
            last = u.se;
        }
        else{
            ans[u.idx] = brut(u.fi, u.se);
        }
    }

    for(auto u: ans)
        cout << u << endl;
}
