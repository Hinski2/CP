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

#define a "Ashishgup"
#define f "FastestFinger"

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1){
            cout << "FastestFinger" << endl;
            continue;
        }
        if(n == 2){
            cout << "Ashishgup" << endl;
            continue;
        }

        bool tak = false;
        for(int i = 1; i <= n; i *= 2)
            if(i == n) tak = 1;
        if(tak){
            cout << "FastestFinger" << endl;
            continue;
        }

        if(n % 2 == 0){
            n /= 2;
            bool prime = true;
            for(int i = 2; i * i <= n; i++)
                if(n % i == 0) prime = false;
            
            if(prime){
                cout << "FastestFinger" << endl;
                continue;
            }
        }
        cout << "Ashishgup" << endl;
    }
}
