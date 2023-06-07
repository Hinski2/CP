#include <bits/stdc++.h>
using namespace std;

const int mak = 105;

int n, cap;
long long dp[mak][100005];

vector<pair<int, int>>p(mak);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> cap;
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;

        p[i] = {a, b};
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= cap; j++)
        {
            int zostalo = j - p[i].first;
            if(zostalo > 0)
            {
                dp[i][j] = max(dp[i - 1][j], p[i].second + dp[i - 1][zostalo]);
            } 
            else if(zostalo == 0)
            {
                dp[i][j] = max(dp[i - 1][j], 1LL * p[i].second);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][cap] << "\n";
}