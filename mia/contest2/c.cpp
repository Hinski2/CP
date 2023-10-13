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

int n, p;
string s;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p >> s;
}

int main(){
    get_input();

    if(p <= 1){
        cout << "NO\n";
        return 0;
    }

    int idx = -1;
    char before = s[0];

    for(int i = n - 1; i >= 0 && idx == -1; i--){
        for(int j = s[i]; j < 'a' + p - 1 && idx == -1; j++){
            s[i]++;

            if(i > 1 && s[i] != s[i - 1] && s[i] != s[i - 2]) idx = i;
            else if(i == 1 && s[i] != s[i - 1]) idx = i;
            else if(i == 0) idx = i;
        }
    }
    if(idx == 0 && before == s[0]){
        cout << "NO\n";
        return 0;
    }

    for(int i = idx + 1; i < n; i++){
        s[i] = '#';
        for(char j = 'a'; j < 'a' + p; j++){
            if(i > 1 && j != s[i - 1] && j != s[i - 2]){
                s[i] = j;
                break;
            }
            else if(i == 1 && j != s[i - 1]){
                s[i] = j;
                break;
            }
        }
        if(s[i] == '#'){
            cout << "NO\n";
            return 0;
        }
    }

    cout << s << endl;
}
