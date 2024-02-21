#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int,null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
//erase: oms.erase(oms.upper_bound(value))

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

struct numb{
    ll a;
    ll b;
};

int len(int x){
    int ans = 0;
    while(x){
        ans++;
        x /= 10;
    }

    return ans;
}

numb convert(int a, int b, int l){
    int delta = l - len(a);
    numb n = {a, b - delta};
    for(int i = 0; i < delta; i++)
        n.a *= 10;
    
    return n;
}

char compare(numb a, numb b){
    if(a.b == b.b && a.a == b.a) return '=';
    if(a.b == b.b){
        if(a.a > b.a) return '>';
        else return '<';
    }
    if(a.b > b.b) return '>';
    return '<';
}

int main(){
    io; int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int c, d; cin >> c >> d;

        int l = max(len(a), len(c));
        numb l1 = convert(a, b, l);
        numb l2 = convert(c, d, l);

        cout << compare(l1, l2) << endl;
    }
}
