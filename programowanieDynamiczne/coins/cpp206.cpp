#include <bits/stdc++.h>
using namespace std;

const int mak = 3000;

int n;
double arr[mak][2];
double dp[mak][mak];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    
    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i][0];
        arr[i][1] = 1 - arr[i][0];
    }

    //liczenie
    dp[1][1] = arr[1][0];
    dp[1][0] = arr[1][1];

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            dp[i + 1][j] += dp[i][j] * arr[i + 1][1];
            dp[i + 1][j + 1] += dp[i][j] * arr[i + 1][0];
        }
    }

    double ans = 0;
    for(int i = (n + 1) / 2; i <= n; i++)
    {
        ans += dp[n][i];
    }

    //wypisanie wyniku
    cout << ans << "\n";
}