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
const ll mak = (ll) 1e15 + 7;

vector<ll> recepie(3), ammount(3), price(3);
ll cash;

bool check(ll mid){
    ll cena = 0;
    cena += price[0] * max(0LL, recepie[0] * mid - ammount[0]);
    cena += price[1] * max(0LL, recepie[1] * mid - ammount[1]);
    cena += price[2] * max(0LL, recepie[2] * mid - ammount[2]);

    return cena <= cash;
}


int main(){
    io; string s; cin >> s;

    for(auto u: s){
        if(u == 'B') recepie[0]++;
        else if(u == 'S') recepie[1]++;
        else recepie[2]++;
    }

    cin >> ammount;
    cin >> price;
    cin >> cash;

    ll l = 0, r = mak, mid;
    while(l < r){
        mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;
}
