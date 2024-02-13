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

ll solve(string s, string dig){
    long long unsigned ans = inf;

    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == dig[0]){
            for(int j = s.size() - 1; j > i; j--){
                if(s[j] == dig[1]) ans = min(ans, (long long unsigned)s.size() - i - 2);
            }
        }
    }

    return ans;
}


int main(){
    io; int t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll mini = inf;
        mini = min(mini, solve(s, "00"));
        mini = min(mini, solve(s, "25"));
        mini = min(mini, solve(s, "50"));
        mini = min(mini, solve(s, "75"));
        cout << mini << endl;
    }
}
