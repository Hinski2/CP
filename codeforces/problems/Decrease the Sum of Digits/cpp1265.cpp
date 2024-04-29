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

vector<int> ull_to_vector(unsigned long long x){
    vector<int> v(1);
    while(x){
        v.pb(x % 10);
        x /= 10;
    }

    reverse(v.begin() + 1, v.end());
    return v;
}

unsigned long long Sum(vector<int> &v){
    unsigned long long s = 0;
    for(auto u: v)
        s += u;
    return s;
}

unsigned long long solve(){
    unsigned long long n, s; cin >> n >> s;
    unsigned long long ans = 0, mult = 1;
    vector<int> v = ull_to_vector(n);
    unsigned long long sum = Sum(v);

    for(int i = v.size() - 1; sum > s; i--, mult *= 10){
        if(v[i] == 10){
            v[i - 1]++;
            sum -= 9;
            v[i] = 0;
            continue;
        }

        ans += (10 - v[i]) * mult;
        sum -= v[i] - 1;
        v[i] = 0;
        v[i - 1]++;
    }

    return ans;
}

int main(){
    io; int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
 