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

int policz(string t){
    int n = t.size(), ans = 0;
    vector<int> pi(n);
     for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && t[i] != t[j])
            j = pi[j-1];
        if (t[i] == t[j])
            j++;
        pi[i] = j;
    }

    return pi[n - 1];
}

int main(){
    io; 
    string s; cin >> s;
    string t; cin >> t;

    int occs[2] = {0}, occt[2] = {0};
    for(auto u: s) 
        if(u == '0') occs[0]++;
        else occs[1]++;
    for(auto u: t) 
        if(u == '0') occt[0]++;
        else occt[1]++;


    int ile = (t.size() == 1 ? 0 : policz(t));

    int new_occt[2] = {occt[0], occt[1]};
    for(int i = 0; i < ile; i++){
        if(t[i] == '0') new_occt[0]--;
        else new_occt[1]--;
    }

    //wypisywanie
    if(occs[0] >= occt[0] && occs[1] >= occt[1]){
        cout << t;
        occs[0] -= occt[0];
        occs[1] -= occt[1];
    }
    while(occs[0] >= new_occt[0] && occs[1] >= new_occt[1]){
        for(int i = ile; i < t.size(); i++)
            cout << t[i];
        
        occs[0] -= new_occt[0];
        occs[1] -= new_occt[1];
    }

    while(occs[0]--) cout << 0;
    while(occs[1]--) cout << 1;
    cout << endl;
}
