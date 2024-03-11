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

void solve(){
    int n = 18;
    vector<int> a(18), b(18);
    cin >> a >> b;

    map<int, int> mapa, mapb;
    for(int i = 0; i <= 10; i++)
        mapa[i] = 0, mapb[i] = 0;

    int suma = 0, sumb = 0;
    for(int i = 0; i < n; i++){
        suma += a[i];
        sumb += b[i];

        mapa[a[i]] += 1;
        mapb[b[i]] += 1;
    }

    if(suma > sumb){
        cout << "Algosia" << endl;
        return;
    }
    if(suma < sumb){
        cout << "Bajtek" << endl;
        return;
    }
    
    for(int i = 10; i >= 0; i--){
        if(mapa[i] > mapb[i]){
            cout << "Algosia" << endl;
            return;
        }
        else if(mapa[i] < mapb[i]){
            cout << "Bajtek" << endl;
            return;
        }
    }

    cout << "remis" << endl;
}

int main(){
    io; 
    solve();
}
