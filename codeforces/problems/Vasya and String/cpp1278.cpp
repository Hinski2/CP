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

int n, k;
int sprawdz(vector<int> &v){
    int use = 0, l = 1, ans = 0;
    for(int r = 1; r <= n; r++){
        use += v[r];
        while(use > k && l < r)
            use -= v[l++];
        ans = max(ans, r - l + 1);
    }

    return ans;
}

int main(){
    io; cin >> n >> k;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        v[i] = c - 'a';
    }

    int ans = sprawdz(v);
    for(int i = 1; i <= n; i++)
        v[i] ^= 1;
    ans = max(ans, sprawdz(v));
    cout << ans << endl;
}
