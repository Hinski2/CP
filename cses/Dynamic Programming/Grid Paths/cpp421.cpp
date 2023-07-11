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
const int mak = 1005;

void read_from_file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int n;
int ways[mak][mak], accesable[mak][mak];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;

            if(c == '.') accesable[i][j] = 1;
        }

    ways[1][1] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(!accesable[i][j]) continue;

            ways[i][j + 1] += ways[i][j]; ways[i][j + 1] %= mod;
            ways[i + 1][j] += ways[i][j]; ways[i + 1][j] %= mod;
        }

    if(!accesable[n][n]) ways[n][n] = 0;
    cout << ways[n][n] << '\n';
}
