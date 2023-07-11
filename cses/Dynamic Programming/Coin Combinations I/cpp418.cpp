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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    //get input
    int n, target;
    cin >> n >> target;

    vector<ll>value, coin;
    value.resize(target + 1);

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        coin.push_back(x);
    }

    //calculate
    value[0] = 1;
    for(int i = 0; i < target; i++)
        for(auto u: coin)
            if(u + i <= target){
                value[i + u] += value[i];
                value[i + u] %= mod;
            }

    cout << value[target] << '\n';
}
