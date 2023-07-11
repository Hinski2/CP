#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;

void read_from_file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int n, budget;
vector<int> pages, price, dp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    cin >> n >> budget;
    pages.resize(n);
    price.resize(n);
    dp.resize(budget + 1);

    for(int i = 0; i < n; i++)
        cin >> price[i];
    for(int i = 0; i < n; i++)
        cin >> pages[i];

    for(int book = 0; book < n; book++)
        for(int cost = budget; cost >= price[book]; cost--)
            dp[cost] = max(dp[cost], pages[book] + dp[cost - price[book]]);
            
    
    int ans = 0;
    for(auto u: dp)
        ans = max(ans, u);
    
    cout << ans << '\n';
}
