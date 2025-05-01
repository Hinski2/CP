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
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

struct Machina{
    map<int, int> m;
    int unique = 0;

    void add(int x){
        if(m[x] == 0) unique++;
        m[x]++; 

    }

    void remove(int x){
        if(m[x] == 1) unique--;
        m[x]--;

        if(m[x] == 0) m.erase(x);
    }

    int min(){
        return m.begin() -> first;
    }

    int max(){
        return m.rbegin() -> first;
    }

    int dif(){
        return max() - min();
    }
};

int solve(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    sort(all(v));

    int ans = 0;
    Machina machina;

    for(int r = 0, l = 0; r < n; r++){
        machina.add(v[r]);
        while(machina.dif() + 1 > n){
            machina.remove(v[l++]);
        }

        ans = max(ans, machina.unique);
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}

