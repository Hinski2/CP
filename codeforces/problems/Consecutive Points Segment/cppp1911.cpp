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
#define yn (solve() ? "YES": "NO")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

bool solve(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;

    int gap2 = 0, gap3 = 0;
    for(int i = 1; i < n; i++){
        if(v[i - 1] + 1 != v[i]){
            int dist = v[i] - v[i - 1];
            if(dist == 2) gap2++;
            else if(dist == 3) gap3++;
            else return 0;
            
            if(gap2 > 2 or gap3 > 1 or (gap2 and gap3)) return 0;
        }
    }

    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << yn << endl;
}

