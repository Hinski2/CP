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

int t;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

void solve(string a, string b){
    char c = a[0]; bool onlyOne = true;
    int lcm = a.size() / __gcd(a.size(), b.size()) * b.size();
    
    string s1;
    for(int i = 1; i <= lcm / a.size(); i++)
        s1 += a;
    string s2;
    for(int i = 1; i <= lcm / b.size(); i++)
        s2 += b;
    
    for(int i = 0; i < lcm; i++)
        if(s1[i] != s2[i]){
            cout << -1 << endl;
            return;
        }
    
    cout << s1 << endl;
}




int main(){
    get_input();

    string a, b;
    while(t-- && cin >> a >> b)
        solve(a, b);
}
