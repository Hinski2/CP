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
const int inf = 1e8 + 7;
const int mak = 2e5 + 7;


int solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> r(n);

    r[n - 1] = (s[n - 1] == '0' ? inf : 0);
    for(int i = n - 2; i >= 0; i--){
        if(s[i] == '0') r[i] = r[i + 1] + 1;
        else r[i] = 0;
    }

    int ans = 0, from_last_one = inf;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') from_last_one = 0;
        if(from_last_one > k && r[i] > k){
            from_last_one = 0;
            ans++;
        }
        from_last_one++;
    }
    
    return ans;
}
int main(){
    io; int t; cin >>  t;
    while(t--)
        cout << solve() << endl;
}
