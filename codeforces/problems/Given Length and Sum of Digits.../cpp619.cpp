#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1

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

int n, s;
string ans;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
}

inline bool can(int m, int sum){
    return sum >= 0 && m * 9 >= sum;
}

int main(){
    get_input();
    if(s == 0 && n != 1 || n * 9 < s){
        cout << "-1 -1\n";
        exit(0);
    }
    if(s== 0 && n == 1){
        cout << "0 0\n";
        exit(0);
    }

    int sum = s;
    for(int i = 0; i < n; i++)
        for(int dig = 0; dig < 10; dig++)
            if((i > 0 || dig > 0 || (n == 1 && dig == 0)) && can(n - i - 1, sum - dig)){
                ans += char('0' + dig);
                sum -= dig;
                break;
            }
    cout << ans << endl;

    ans = "";
    sum = s;
    for(int i = 0; i < n; i++)
        for(int dig = 9; dig >= 0; dig--)
            if(can(n - i - 1, sum - dig)){
                ans += char('0' + dig);
                sum -= dig;
                break;
            }
    cout << ans << endl;

}
