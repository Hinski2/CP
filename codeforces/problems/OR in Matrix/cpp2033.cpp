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
const int mak = 107;

int n, m;
int b[mak][mak], row[mak], col[mak], a[mak][mak];
bool ok_row[mak], ok_col[mak];

void col_row(int i) {
    for(int j = 1; j <= m; j++)
        a[i][j] = 1;
}

void col_col(int j) {
    for(int i = 1; i <= n; i++)
        a[i][j] = 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) {
            cin >> b[i][j];
            row[i] += b[i][j];
            col[j] += b[i][j];
        }

    bool ok = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(b[i][j] and row[i] != m and col[j] != n)
                ok = false;
            
            if(b[i][j] and row[i] == m and col[j] == n) {
                a[i][j] = 1;
                ok_row[i] = true;
                ok_col[j] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++)
        if(row[i] == m and !ok_row[i]) ok = false;
    for(int i = 1; i <= m; i++)
        if(col[i] == n and !ok_col[i]) ok = false;


    if(!ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    }
}
