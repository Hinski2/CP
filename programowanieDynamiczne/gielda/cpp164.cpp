#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n, tip;
int arr[mak];
long long dp[mak], maks = -INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    //wczytywanie
    cin>>n>>tip;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++)
    {
        long long case1 = dp[i - 1];
        long long case2 = arr[i] - tip + maks;

        dp[i] = max(case1, case2);
        maks = max(maks, dp[i - 1] - arr[i]);
    }

    cout << dp[n] << "\n";
}