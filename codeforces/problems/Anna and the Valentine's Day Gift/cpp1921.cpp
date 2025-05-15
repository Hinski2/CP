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

int Anna = 0, Sasha = 1;
struct word {
    int len;
    int zeros;

    bool operator < (const word &other) const {
        if(zeros != other.zeros) return zeros > other.zeros;
        return len > other.len;
    }
};

int solve(){
    auto get_len = [](int x) {
        int ans = 0;
        while(x) {
            ans++;
            x /= 10;
        }
        return ans;
    };

    auto get_zeros = [](int x) {
        int ans = 0;
        while(x % 10 == 0) {
            ans++;
            x /= 10;
        }

        return ans;
    };


    int n, m; cin >> n >> m;
    multiset<word> s;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        word w = {get_len(x), get_zeros(x)};
        s.insert(w);
    }

    int move = Anna;
    while(1) {
        if(move == Anna) {
            auto a = *s.begin(); s.erase(s.begin());
            word w = {a.len - a.zeros, 0};
            s.insert(w);

            if(s.size() == 1) break;
        } else {
            auto a = *s.begin(); s.erase(s.begin());
            auto b = *prev(s.end()); s.erase(prev(s.end()));
            word w = {a.len + b.len, b.zeros};
            s.insert(w);
        }

        move ^= 1;
    }

    return s.begin() -> len > m ? Sasha : Anna;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << (solve() == Anna ? "Anna" : "Sasha") << endl;
        
}
