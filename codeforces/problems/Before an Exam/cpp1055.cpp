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

int main(){
    io; int days, totalTime; cin >> days >> totalTime;
    vector<pii> v(days + 1);
    for(int i = 1; i <= days; i++)
        cin >> v[i].fi >> v[i].se;
    
    vector<int> pozostaloMin(days + 2);
    for(int i = days; i > 0; i--)
        pozostaloMin[i] = pozostaloMin[i + 1] + v[i].fi;

    bool udasie = true; 
    vector<int> ans(days + 1);
    for(int i = 1; i <= days; i++){
        int d = min(v[i].se, totalTime - pozostaloMin[i + 1]);
        if(d < v[i].fi) udasie = 0;

        ans[i] = d;
        totalTime -= d;
    }
    if(totalTime != 0) udasie = 0;

    if(udasie){
        cout << "YES" << endl;
        for(int i = 1; i <= days; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
