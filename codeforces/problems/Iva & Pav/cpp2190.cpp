#include <bits/stdc++.h>
using namespace std;

// geometry
template<typename T>
ostream& operator<<(ostream& os, const pair<T, T>& p) {
    os << p.first << ' ' << p.second << '\n';
    return os;
}

template<typename T> 
istream& operator>>(istream& is, pair<T, T>& p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T>
pair<T, T> operator + (const T& a, const T& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename T>
pair<T, T> operator - (const T& a, const T& b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

template<typename T>
T operator * (const T& a, const T& b) {
    return a.first * b.second - a.second * b.first;
}

template<typename T>
T cross_product(const T& a, const T& b) {
    return a * b;
}

template<typename T>
T cross_product(const T& a, const T& b, const T& c) {
    return (b - a) * (c - a);
}

// vector
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const auto &u: v) {
        os << u << ' ';
    }
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for(auto& u : v) {
        is >> u;
    }
    return is;
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
const int smak = 448;

struct SS{
    int n;
    int small[mak]{}, big[smak]{};

    SS(int n, vector<int> &v) 
        : n(n) {

        for(int i = 0; i < n; i++)
            small[i] = v[i];

        for(int i = 0; i < smak; i++) {
            if(i * smak >= n) break;

            big[i] = small[i * smak];
            for(int j = 0; j < smak; j++) {
                if(i * smak + j >= n) break;
                big[i] &= small[i * smak + j];
            }
        }
    }

    int get_big_idx(int small_idx) const {
        return small_idx / smak;
    }

    int get_last(int small_idx) const {
        return min(n, (get_big_idx(small_idx) + 1) * smak - 1);
    }

    int find(int l, int k) {
        if(small[l] < k) return -1;

        int numb = small[l], last_small_idx = get_last(l);
        for(int small_idx = l; small_idx <= last_small_idx; small_idx++) {
            if((numb & small[small_idx]) < k) return small_idx;
            else numb &= small[small_idx];
        }

        int big_idx = get_big_idx(last_small_idx + 1);
        int small_idx = smak * (smak - 1) - 1;
        for(; big_idx < smak; big_idx++) {
            if((numb & big[big_idx]) < k) {
                small_idx = big_idx * smak;
                break;
            } else {
                numb &= big[big_idx];
            }
        }

        last_small_idx = get_last(small_idx);
        for(; small_idx <= last_small_idx; small_idx++) {
            if((numb & small[small_idx]) < k) return small_idx;
            else numb &= small[small_idx];
        }

        return n;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    SS ss(n, v);

    int t; cin >> t;
    while(t--) {
        int l, k; cin >> l >> k; l--;
        cout << ss.find(l, k) << ' ';
    }

    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
