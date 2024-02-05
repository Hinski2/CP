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

inline bool to_bool(char c){
    return c - '0';
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, y = 0;

    for(int i = 0; i < s.size(); i++)
        if(to_bool(s[i]) == 0) x++;
        else break;
    
    for(int i = s.size() - 1; i >= 0; i--)
        if(to_bool(s[i]) == 1) y++;
        else break;

    bool is0 = false;
    for(auto u: s)  if(to_bool(u)) is0 = true;
    if(!is0){
        cout << s << endl;
        return;
    }

    bool nondec = true;
    for(int i = 0; i < n - 1; i++)
        if(to_bool(s[i]) == 1 && to_bool(s[i + 1]) == 0) nondec = 0;
    if(nondec){
        cout << s << endl;
        return;
    }
    
    for(int i = 0; i <= x; i++) cout << '0';
    for(int i = 0; i < y; i++) cout << '1';
    cout << endl;
}

int main(){
    io; int t; cin >> t;
    while(t--)
        solve();
}
