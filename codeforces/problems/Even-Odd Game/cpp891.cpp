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

#define a "Alice"
#define b "Bob"
#define ti "Tie"

string solve(){
    int n; cin >> n;
    priority_queue<ll> even, odd;
    for(int i = 0; i < n; i++){
        int x; cin >> x;

        if(x & 1) odd.push(x);
        else even.push(x);
    }

    ll alice = 0, bob = 0, i = 0;
    while(!even.empty() || !odd.empty()){
        if(i % 2 == 0){
            if(!even.empty() && !odd.empty()){
                if(even.top() >= odd.top()) alice += even.top(), even.pop();
                else odd.pop();
            }
            else if(!even.empty()) alice += even.top(), even.pop();
            else if(!odd.empty()) odd.pop();
        }
        else{
            if(!even.empty() && !odd.empty()){
                if(even.top() <= odd.top()) bob += odd.top(), odd.pop();
                else even.pop();
            }
            else if(!even.empty()) even.pop();
            else if(!odd.empty()) bob += odd.top(), odd.pop();
        }
    i ^= 1;
    }

    if(alice == bob) return ti;
    return (alice > bob ? a : b);
}

int main(){
    io; int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
