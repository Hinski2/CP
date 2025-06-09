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

template<typename T> T max(const vector<T> &v){
    T maxi = v[0];
    for(auto u: v) maxi = max(maxi, u);
    return maxi;
}

template<typename T> T min(const vector<T> &v){
    T mini = v[0];
    for(auto u: v) mini = min(mini, u);
    return mini;
}

template<typename T> unsigned arg_max(const vector<T> &v){
    T maxi = v[0];
    unsigned pos = 0;
    for(unsigned i = 1; i <= v.size(); i++)
        if(v[i] > maxi){
            maxi = v[i];
            pos = i;
        }
    return pos;
}

template<typename T> unsigned arg_min(const vector<T> &v){
    T mini = v[0];
    unsigned pos = 0;
    for(unsigned i = 1; i <= v.size(); i++)
        if(v[i] < mini){
            mini = v[i];
            pos = i;
        }
    return pos;
}

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define yn (solve() ? "YES" : "NO")
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

struct Monster {
    int health;
    int pos;

    bool operator < (const Monster& other) const {
        if(pos != other.pos) return pos < other.pos;
        return health < other.health;
    }
};

bool solve() {
    int n, k; cin >> n >> k;
    vector<Monster> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].health;
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i].pos;
        v[i].pos = abs(v[i].pos);
    }

    sort(all(v));
    vector<Monster> monsters = {v[0]};
    monsters.reserve(n + 1);
    for(int i = 1; i < n; i++) {
        auto& u = v[i];
        if(u.pos == monsters.back().pos) {
            monsters.back().health += u.health;
        } else {
            monsters.push_back(u);
        }
    }


    int sum_health = 0;
    for(auto u: monsters) {
        sum_health += u.health;
        int damage = u.pos * k;
        if(damage < sum_health) return 0;
    }
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << yn << endl;
}
