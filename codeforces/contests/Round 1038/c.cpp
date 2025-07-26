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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

struct S{
    int x, y, idx;
} v[mak];

bool by_x(const S& a, const S& b) {
    if(a.x != b.x) return a.x > b.x;
    return a.idx > b.idx;
}

bool by_y(const S& a, const S& b) {
    if(a.y != b.y) return a.y > b.y;
    return a.idx > b.idx;
}

bool cmp(const S& a, const S& b) {
    return a.x + a.y > b.x + b.y;
}

int suma;
void connect(vector<S> &a, vector<S> &b) {
    while(!a.empty() and !b.empty()){
        cout << a.back().idx << ' ' << b.back().idx << endl;
        suma += abs(a.back().x - b.back().x) + abs(a.back().y - b.back().y);
        a.pop_back(), b.pop_back();
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].idx = i + 1;
    }

    vector<S> part[4];
    for(int i = 0; i < n; i++) {
        auto u = v[i];
        if(u.x >= 0 and u.y >= 0) part[0].pb(u);
        else if(u.x >= 0 and u.y < 0) part[1].pb(u);
        else if(u.x < 0 and u.y < 0) part[2].pb(u);
        else part[3].pb(u);
    }

    suma = 0;
    connect(part[0], part[2]);
    connect(part[1], part[3]);

    sort(all(part[0]), by_y);
    sort(all(part[1]), by_y);
    reverse(all(part[1]));
    connect(part[0], part[1]);

    sort(all(part[2]), by_y);
    sort(all(part[3]), by_y);
    reverse(all(part[2]));
    connect(part[2], part[3]);

    sort(all(part[0]), by_x);
    sort(all(part[3]), by_x);
    reverse(all(part[0]));
    connect(part[0], part[3]);

    sort(all(part[2]), by_x);
    sort(all(part[1]), by_x);
    reverse(all(part[2]));
    connect(part[2], part[1]);

    for(int i = 0; i < 4; i++) {
        int m = part[i].size();
        sort(all(part[i]), cmp);

        for(int j = 0; j < m / 2; j++) {
            cout << part[i][j].idx << ' ' << part[i][m - j - 1].idx << endl;
            suma += abs(part[i][j].x - part[i][m - j - 1].x)
                  + abs(part[i][j].y - part[i][m - j - 1].y);
        }
    }
    
    cout << suma << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
