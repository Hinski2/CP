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
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return make_pair(p1.first - p2.first, p1.second - p2.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator*(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return make_pair(p1.first * p2.first, p1.second * p2.second);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << p.first << ' ' << p.second;
    return os;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    is >> p.first >> p.second;
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
typedef unsigned long long ull;
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

vector<ll> ans;
bool sprawdz(ull x, set<ull> s, ull deep){
    if(s.empty()){
        return true;
    }

    if(x % 3 == 0 && s.count(x / 3)){
        s.erase(x / 3);
        if(sprawdz(x / 3, s, deep + 1)){
            ans[deep] = x / 3;
            return 1;
        }
        s.insert(x / 3);
    }
    if(s.count(x * 2)){
        s.erase(x * 2);
        if(sprawdz(x * 2, s, deep + 1)){
            ans[deep] = x * 2;
            return 1;
        }
        s.insert(x * 2);
    }

    return 0;
}

int main(){
    io; int n; cin >> n;
    vector<ull> v(n); cin >> v;
    set<ull> s;
    ans.resize(n);
    for(int i = 0; i < n; i++)
        s.insert(v[i]);

    for(int i = 0; i < n; i++){
        s.erase(v[i]);
        if(sprawdz(v[i], s, 1)){
            ans[0] = v[i];
            break;
        }
        s.insert(v[i]);
    }
    cout << ans << endl;
}
