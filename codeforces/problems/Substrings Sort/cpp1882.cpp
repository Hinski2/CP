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

// a before b?
bool cmp(const string &a, const string &b){
    if(a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int n; 
vector<string> vs;

// a in b?
bool in(int a_i, int b_i){
    const string &a = vs[a_i];
    const string &b = vs[b_i];

    for(int i = 0; i + a.size() <= b.size(); i++){
        bool ok = true;
        for(int j = 0; j < a.size() and ok; j++){
            if(a[j] != b[i + j]) ok = false;
        }

        if(ok) return 1;
    }

    return 0;
}

int main(){
    io;
    cin >> n;
    vs.resize(n); cin >> vs;
    sort(all(vs), cmp);

    for(int i = 1; i < n; i++){
        if(vs[i - 1].size() != vs[i].size()){
            if(!in(i - 1, i)){
                cout << "NO" << endl;
                return 0;
            }
        } else {
            if(vs[i - 1] != vs[i]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for(auto u: vs){
        cout << u << endl;
    }
}
