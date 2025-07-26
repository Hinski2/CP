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

// bool check(int mid) {
//     int skipped = 0;
//     list<int> catt;

//     for(int i = 1; i <= n; i++) {
//         if(!catt.empty() and catt.back() > v[i]) {
//             if(skipped) {
//                while(catt.front() != skipped) catt.pop_front();
//                catt.pop_front();
//             }

//             skipped = v[i];
//         }
//         catt.push_back(v[i]);
//         if(catt.size() + (skipped ? -1 : 0) >= mid) return 1;
//     }

//     return 0;
// } 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n + 1); for(int i = 1; i <= n; i++) cin >> v[i];

    int ans = 1;
    vector<int> r(n + 1, 1);
    for(int i = n - 1; i >= 1; i--)
        if(v[i] < v[i + 1]) r[i] = r[i + 1] + 1;

    vector<int> l(n + 1, 1);
    for(int i = 2; i <= n; i++)
        if(v[i - 1] < v[i]) l[i] = l[i - 1] + 1;

    ans = max(ans, *max_element(all(l)));
    ans = max(ans, *max_element(all(r)));

    for(int i = 1; i <= n - 2; i++)
        if(v[i] < v[i + 2]) ans = max(ans, l[i] + r[i + 2]);
    
    cout << ans << endl;
}
