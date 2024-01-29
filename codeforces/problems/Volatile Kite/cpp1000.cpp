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
typedef long double ld;
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

int n;

ld dist(pll a, pll b, pll c){
    pair<ld, ld> ac = {c.fi - a.fi, c.se - a.se};
    pair<ld, ld> bc = {c.fi - b.fi, c.se - b.se};

    ld cross_product = ac.fi * bc.se - ac.se * bc.fi;
    pair<ld, ld> ab = {b.fi - a.fi, b.se - a.se};
    ld len_ab = sqrt(ab.fi * ab.fi + ab.se * ab.se);

    return abs(cross_product / len_ab);
}
int main(){
    io; cin >> n;
    vector<pll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].fi >> v[i].se;

    ld ans = 1e16;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n; j++){
            if(abs(i - j) > 2) continue;

            for(int k = 0; k < 2 * n; k++){
                if(abs(i - k) > 2) continue;

                set<ll> s;
                s.insert(i % n);
                s.insert(j % n);
                s.insert(k % n);

                if(s.size() != 3) continue;
                ld subAns = dist(v[i % n], v[j % n], v[k % n]);
                ans = min(ans, subAns);
            }
        }
    }  

    printf("%.8lf\n", (double) ans / 2);
}
