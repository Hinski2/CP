#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v){
    for(auto& u : v){
        is >> u;
    }
    return is;
}

template<typename T> long long sum(const vector<T> &v){
    long long s = 0;
    for(auto u: v) s += u;
    return s;
}

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define yn (solve() ? YES : NO)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

struct Item{
    int idx;
    int fi;
    int se;

    bool operator < (const Item &other) const {
        if(fi - se != other.fi - other.se)
            return fi - se > other.fi - other.se;
        return idx < other.idx;
    }
};

int n, m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<Item> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
        v[i].idx = i;
    }

    sort(all(v));

    ll suma = 0;
    for(int i = 0; i < n; i++) suma += v[i].fi;

    if(suma <= m){
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        suma -= v[i].fi; 
        suma += v[i].se;

        if(suma <= m){
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}

