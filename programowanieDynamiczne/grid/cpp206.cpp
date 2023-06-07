#include <bits/stdc++.h>
using namespace std;

const int mak = 1005;
const int mod = 1e9 + 7;

int n, m;
int dp[mak][mak];
bool grid[mak][mak];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //wczytywanie
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;

            if(c == '.') grid[i][j] = true;
        }
    }

    //liczenie
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(grid[i][j])
            {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            }
        }
    }

    //wypisanie wyniku
    cout << dp[n][m] << "\n";
}