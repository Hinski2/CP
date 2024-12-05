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

void solve(){
    int zero, one; cin >> zero >> one;
    string s; cin >> s;

    int a = 0, b = 0;
    for(auto u: s)
        if(u == '0') a++;
        else if(u == '1') b++;
    for(int i = 0, j = s.size() - 1; i < j; i++, j--){
        if(s[i] == '?' and s[j] == '0') s[i] = '0', a++;
        else if(s[i] == '?' and s[j] == '1') s[i] = '1', b++;
        else if(s[i] == '0' and s[j] == '?') s[j] = '0', a++;
        else if(s[i] == '1' and s[j] == '?') s[j] = '1', b++;
        else if(s[i] != s[j]){
            cout << -1 << endl;
            return;
        }
    }

    if(a > zero or b> one){
        cout << -1 << endl;
        return;
    }

    for(int i = 0, j = s.size() -1; i < j; i++, j--)
        if(s[i] == '?' and zero - a > one - b) a += 2, s[i] = '0', s[j] = '0';
        else if (s[i] == '?') b += 2, s[i] = '1', s[j] = '1';

    if(a > zero or b > one){
        cout << -1 << endl;
        return;
    }

    if(s.size() % 2){
        if(s[s.size() / 2] == '?' and zero - a > one - b) a += 1, s[s.size() / 2] = '0';
        else if (s[s.size() / 2] == '?') b += 1, s[s.size() / 2] = '1';
    }

    if(a != zero or b != one){
        cout << -1 << endl;
        return;
    }

    cout << s << endl;
}

int main(){
    io; int t; cin >> t;
    while(t--)
        solve();
}
