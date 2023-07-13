#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back

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
const int mak = 5007;

int dp[mak][mak];
string str1, str2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str1 >> str2;
    str1 = '#' + str1;
    str2 = '#' + str2;

    for(int i = 0; i < str1.size(); i++)
        for(int j = 0; j < str2.size(); j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;

            else if(str1[i] == str2[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }

    // for(int i = 0; i < str1.size(); i++){
    //     for(int j = 0; j < str2.size(); j++) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    cout << dp[str1.size() - 1][str2.size() - 1] << '\n';
}
