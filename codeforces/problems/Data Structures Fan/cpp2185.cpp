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

struct Node {
    int propagate;
    int xor0, xor1;
};

struct Tree {
    int n, base;
    vector<Node> nodes; 
    vector<int> v;

    Tree(int n, const string &s, vector<int> nums)
        : n(n), v(move(nums)) {
        
        base = 1;
        while(base < n) {
            base *= 2;
        }

        nodes.resize(base * 2);


        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                nodes[base + i] = {0, v[i], 0}; 
            } else {
                nodes[base + i] = {0, 0, v[i]}; 
            }
        }

        for(int i = base - 1; i; i--) {
            nodes[i] = {
                0,
                nodes[2 * i].xor0 ^ nodes[2 * i + 1].xor0,
                nodes[2 * i].xor1 ^ nodes[2 * i + 1].xor1,
            };
        }
    }

    void change(int l, int r) {
        l--, r--;

        propagate(1);
        _change(0, base - 1, l, r, 1);
    }

    void _change(int tree_range_l, int tree_range_r, int l, int r, int idx) {
        if(r < tree_range_l or l > tree_range_r) {
            return; 
        } else if(l <= tree_range_l and tree_range_r <= r) {
            nodes[idx].propagate ^= 1;
            propagate(idx);
        } else {
            int mid = (tree_range_l + tree_range_r) / 2;

            propagate(2 * idx);
            _change(tree_range_l, mid, l, r, idx * 2);

            propagate(2 * idx + 1);
            _change(mid + 1, tree_range_r, l, r, idx * 2 + 1);

            nodes[idx] = {
                0,
                nodes[2 * idx].xor0 ^ nodes[2 * idx + 1].xor0,
                nodes[2 * idx].xor1 ^ nodes[2 * idx + 1].xor1,
            };
        }
    }

    void propagate(int idx) {
        if(!nodes[idx].propagate) return;
        nodes[idx].propagate = 0;

        swap(nodes[idx].xor0, nodes[idx].xor1);
        if(idx < base) {
            nodes[idx * 2].propagate ^= 1;
            nodes[idx * 2 + 1].propagate ^= 1;
        }
    }

    int querry(int g) {
        propagate(1);
        return g ? nodes[1].xor1 : nodes[1].xor0;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    string s; cin >> s;
    Tree tree(n, s, v);

    int m; cin >> m;
    while(m--) {
        int q; cin >> q;
        if(q == 1) {
            int a, b; cin >> a >> b;
            tree.change(a, b);
        } else {
            int g; cin >> g;
            cout << tree.querry(g) << ' ';
        }
    }

    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
