
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

int solve(){
    int n, w; cin >> n >> w;
    vector<int> amm(21);
    for(int i = 0, x; i < n; i++){
        cin >> x;
        amm[__builtin_ctz(x)]++;
    }

    int ans = 1, space = w;
    while(n--){
        bool s = false;
        for(int i = 20; i >= 0; i--){
            if(amm[i] and space >= (1 << i)){
                space -= (1 << i);
                amm[i]--;
                s = true;
                break;
            }
        }

        if(!s){
            ans++;
            space = w;
            n++;
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}

