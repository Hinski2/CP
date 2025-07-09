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

bool solve() {
    string hit, song; cin >> hit >> song;
    vector<pair<char, int>> hv, sv;

    int cnt = 0; char chr = hit[0];
    for(auto h: hit){
        if(chr == h) cnt++;
        else {
            hv.pb({chr, cnt});
            cnt = 1;
            chr = h;
        }
    }

    if(cnt) {
        hv.pb({chr, cnt});
    }

    cnt = 0, chr = song[0];
    for(auto s: song) {
        if(chr == s) cnt++;
        else {
            sv.pb({chr, cnt});
            cnt = 1;
            chr = s;
        }
    }

    if(cnt) {
        sv.pb({chr, cnt});
    }
    
    if(sv.size() != hv.size()) return 0;
    for(int i = 0; i < sv.size(); i++) {
        if(sv[i].fi != hv[i].fi) return 0;
        if(hv[i].se <= sv[i].se and sv[i].se <= 2*hv[i].se) continue;
        return 0;
    }

    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) 
        cout << yn << endl;
}
