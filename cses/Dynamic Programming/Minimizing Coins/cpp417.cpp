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

int n, target;
vector<int>coins, values;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    //get input
    cin >> n >> target;
    values.resize(target + 1, inf);
    coins.resize(n);

    for(int i = 0; i < n; i++)
        cin >> coins[i];

    //solve
    values[0] = 0;
    for(int i = 0; i <= target; i++)
        for(auto u: coins)
            if(i + u <= target)
                values[i + u] = min(values[i + u], values[i] + 1);

    cout << (values[target] == inf ? -1 : values[target]) << '\n';
}
