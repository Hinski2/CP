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

inline int z(char c){
    return c - '0';
}
string solve(string s){
    bool even = false;
    for(auto u: s) if(z(u) % 2 == 0) even = true;
    if(!even) return "-1";

    int idx = -1;
    for(int i = 0; i < s.size(); i++){
        if(z(s[i]) < z(s[s.size() - 1]) && z(s[i]) % 2 == 0){
            idx = i;
            break;
        }
    }

    if(idx != -1){
        char c = s[s.size() - 1];
        s[s.size() - 1] = s[idx];
        s[idx] = c;

        return s;
    }

    for(int i = s.size() - 1; i >= 0; i--){
        if(z(s[i]) % 2 == 0){
            char c = s[s.size() - 1];
            s[s.size() - 1] = s[i];
            s[i] = c;
            
            break;
        }
    }

    return s;
}

int main(){
    io; string s; cin >> s;
    cout << solve(s) << endl;
}
