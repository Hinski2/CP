#include <bits/stdc++.h>
using namespace std;

const int mak = 3005;

int dp[mak][mak];
string a, b;
vector<char>ans;

int sprawdzenie(int j, int i)
{
    if(a[i] == b[j]) return 1;
    return 0;
}

void wyznacz(int x, int y)
{
    if(!x || !y) return;
    if(dp[x][y - 1] == dp[x][y])  wyznacz(x, y - 1);
    else if(dp[x - 1][y] == dp[x][y]) wyznacz(x - 1, y);
    else
    {
        ans.push_back(a[y - 1]);
        wyznacz(x - 1, y - 1);
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> a >> b;

    //liczenie
    int n = (int) b.size();
    int m = (int) a.size();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int maksuj = max(dp[i - 1][j], dp[i][j - 1]);
        
            if(sprawdzenie(i - 1, j - 1))
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = maksuj;
            }
        }
    }

    // for(int i = 0; i <= n; i++)
    // {
    //     for(int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    wyznacz(n, m);

    //wypisywanie
    for(int i = (int) ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout <<"\n";
}
