#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 1005;

int n, m, ans;
char place[mak][mak];

vector<pii> movee{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

void explore(int i, int j){
    place[i][j] = '#';
    for(auto u: movee){
        if(i + u.fi < 1 | i + u.fi > n | place[i + u.fi][j + u.se] != '.') continue;
        if(j + u.se < 1 | j + u.se > m) continue;

        explore(i + u.fi, j + u.se);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> place[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(place[i][j] == '.'){
                explore(i, j);
                ans++;
            }

    cout << ans << '\n';
}
