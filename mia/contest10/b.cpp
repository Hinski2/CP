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

string solve(){
    string s; cin >> s;
    string t; cin >> t;
    int socc[alf] = {0}, tocc[alf] = {0};
    for(auto u: s) socc[u]++;
    for(auto u: t) tocc[u]++;

    bool usun = false;
    for(int i = 0; i < alf; i++){
        if(tocc[i] > socc[i]) return "need tree\n";
        else if(socc[i] > tocc[i]) usun = true;
    }

    bool zamien = false;
    int idxt = 0;
    for(int i = 0; i < s.size() && idxt < t.size(); i++)
        if(s[i] == t[idxt]) idxt++;

    if(idxt == t.size() && usun) return "automaton\n";
    if(idxt != t.size() && !usun) return "array\n";
    return "both\n";
}

int main(){
    io;
    cout << solve();
}
