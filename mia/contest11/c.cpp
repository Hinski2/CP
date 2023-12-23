#include <bits/stdc++.h>
using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& u : v){
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
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define yn (solve() ? "YES" : "NO")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//erase: oms.erase(oms.upper_bound(value))

struct domino{
    ll x;
    ll h;
    ll idx;
};

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

bool cmp(domino a, domino b){
    return a.x < b.x;
}

const int base = 1 << 17;
int tree[base << 1];

int n;
vector<int> ans;
vector<domino> v;

int znajdz_ostatni(int idx){
    int l = idx, r = n - 1, mid;
    while(l < r){
        mid = (l + r + 1) / 2;
        if(v[idx].x + v[idx].h - 1 >= v[mid].x) l = mid;
        else r = mid - 1;
    }

    return l;
}

int querry(int i, int j){
    if(i == j) return i;

    i += base;
    j += base;

    int ans = max(tree[i], tree[j]);
    while(j - i > 1){
        if(i % 2 == 0) ans = max(ans, tree[i + 1]);
        if(j % 2 == 1) ans = max(ans, tree[j - 1]);

        i >>= 1;
        j >>= 1;
    }

    return ans;
}

void update(int idx, int val){
    idx += base;
    tree[idx] = val;
    idx >>= 1;

    while(idx){
        tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
        idx >>= 1;
    }
}

int main(){
    io; cin >> n;
    v.resize(n);
    ans.resize(n);

    for(int i = 0; i < n; i++){
        cin >> v[i].x >> v[i].h;
        v[i].idx = i;
    }

    sort(all(v), cmp);
    for(int i = n - 1; i >= 0; i--){
        int j = znajdz_ostatni(i);

        tree[i + base] = j; //temp potem to będize wynik
        int wynik = querry(i, j);

        update(i, wynik);
        ans[v[i].idx] = wynik - i + 1;
    }

    cout << ans << endl;
}
