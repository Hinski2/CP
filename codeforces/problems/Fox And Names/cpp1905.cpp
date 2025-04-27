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

int in[alf];
set<int> G[alf];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> ss(n); cin >> ss;
    
    for(int i = 1; i < n; i++){
        auto &a = ss[i - 1];
        auto &b = ss[i];

        int f = 0;
        for(int j = 0; j < min(a.size(), b.size()); j++){
            if(a[j] != b[j]){
                if(!G[a[j]].contains(b[j])){
                    G[a[j]].insert(b[j]);
                    in[b[j]]++;
                }

                f = 1;
                break;
            }
        }
        if(f == 0 and a.size() > b.size()){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    vector<int> leaf;
    for(int i = 'a'; i <= 'z'; i++)
        if(in[i] == 0) leaf.pb(i);

    vector<char> ans;
    while(!leaf.empty()){
        char c = leaf.back(); leaf.pop_back();
        ans.pb(c);

        for(auto u: G[c]){
            in[u]--;
            if(in[u] == 0){
                leaf.pb(u);
            }
        }
    }

    if(ans.size() != 'z' - 'a' + 1){
        cout << "Impossible" << endl;
    } else {
        for(auto u: ans)
            cout << u;
        cout << endl;
    }
}

