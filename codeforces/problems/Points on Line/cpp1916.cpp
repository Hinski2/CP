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

struct Caterpillar {
    int m_dist, ans = 0;
    list<int> vals;

    void add(int x){
        while(!vals.empty() and x - vals.front() > m_dist){
            ans += combinations();
            vals.pop_front();
        }
        vals.push_back(x);
    }

    int combinations(){
        const int &s = vals.size();
        if(s < 3) return 0;
        return (s - 1) * (s - 2) / 2;
    }

    int end_cobm(){
        const int &s = vals.size();
        if(s < 3) return 0;
        return s * (s - 1) * (s - 2) / 6;
    }
} cat;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m_dist; cin >> n >> m_dist;
    cat.m_dist = m_dist;

    for(int i = 0, x; i < n; i++){
        cin >> x;
        cat.add(x);
    }

    cat.ans += cat.end_cobm();
    cout << cat.ans << endl;
}
