#include <bits/stdc++.h>
using namespace std;

const int mak = 1005;

int n;
int wino[mak];
int dp[mak][mak];

int maksimum(int l, int r)
{
    int year = n + l - r;

    if(l == r)
    {
        return dp[l][r] = wino[l] * 5;
    }
    else if(dp[l][r])
    {
        return dp[l][r];
    }
    else
    {
        return dp[l][r] = max(maksimum(l + 1, r) + wino[l] * year, maksimum(l, r - 1) + wino[r] * year);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>wino[i];
    }

    int ans = maksimum(1, n);

    cout<<dp[1][n]<<endl;
}