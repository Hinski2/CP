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

string s;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
}

inline int no(int x){
    return s[x] - '0';
}

int main(){
    get_input();

    int n = s.size();
    bool found = false;
    for(int a = 0; a < n; a++)
        for(int b = a + 1; b < n; b++)
            for(int c = b + 1; c < n; c++)
                if((no(a) * 100 + no(b) * 10 + no(c)) % 8 == 0){
                    cout << "YES\n";
                    cout << no(a) * 100 + no(b) * 10 + no(c);
                    exit(0);
                }

    for(int a = 0; a < n; a++)
        for(int b = a + 1; b < n; b++)
            if((no(a) * 10 + no(b)) % 8 == 0){
                    cout << "YES\n";
                    cout << no(a) * 10 + no(b);
                    exit(0);
                }

    for(int i = 0; i < n; i++)
        if(no(i) % 8 == 0){
                cout << "YES\n";
                cout << no(i);
                exit(0);
            }

    cout << "NO\n";
}