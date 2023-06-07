#include <bits/stdc++.h>
using namespace std;
vector<long long> dp(90,-1);

long long sprawdzenie(long long n)
{
    if(n==1)return 1;
    if(n==2)return 2;

    if(dp[n]!=-1) return dp[n];
    else return dp[n]=sprawdzenie(n-1)+sprawdzenie(n-2);
}

int main()
{
    dp[1]=1;
    dp[2]=2;
    long long x=88;

    sprawdzenie(x);

    for(int i=1;i<=88;i++)
    {
        cout<<i<<". "<<dp[i]<<"\n";
    }
}