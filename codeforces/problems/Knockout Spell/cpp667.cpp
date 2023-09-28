#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second;
 
int n, k, ans;
int v[1005][1005];
 
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
 
    int a = k - 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> v[i][j];
    for(int i = 1; i <= n - a; i++)
        for(int j = 1; j <= n - a; j++)
            if(v[i][j] == v[i + a][j] && v[i][j] == v[i][j + a] &&
                v[i][j] == v[i + a][j + a]) ans++;
    cout << ans << '\n';
}