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
const int base = 1 << 18;
const int mak = 1 << 18;

int n; 
vector<int> pos[mak];

struct Tree{
    int node[mak * 2];

    int get_max(int l, int r){
        l += base;
        r += base;
        int ans = max(node[l], node[r]);
        for(; l / 2 != r / 2; l /= 2, r /= 2){
            if(l % 2 == 0) ans = max(ans, node[l + 1]);
            if(r % 2 == 1) ans = max(ans, node[r - 1]);
        }

        return ans;
    }

    void update(int idx, int val){
        idx += base;
        node[idx] = val;
        for(idx /= 2; idx; idx /= 2){
            node[idx] = max(node[idx * 2], node[idx * 2 + 1]);
        }
    }
} tree;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> v(n); cin >> v;
    for(int i = 0; i < n; i++){
        pos[v[i]].pb(i);
    }

    int ans = 0;
    for(int idx = 0; idx < n; idx++){
        int val = v[idx];
        int pos_idx_l = 0;

        while(pos_idx_l < pos[val].size() and pos[val][pos_idx_l] <= idx)
            pos_idx_l++;

        for(int l = pos_idx_l; l < pos[val].size(); l++){
            int new_val = tree.get_max(pos[val][l] + 1, n) + 1;
            ans = max(ans, new_val);
            tree.update(pos[val][l], new_val);
        }
    }

    cout << ans * 2 << endl;
}
