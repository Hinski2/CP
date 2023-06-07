#include <bits/stdc++.h>
using namespace std;

vector<int> dp(100,-1);
int x;

int sprawdzenie(int n)
{
    if(n==1)return 1;
    if(n==2)return 2;
    if(dp[n]!=-1) return dp[n];
    else return dp[n]=sprawdzenie(n-1)+sprawdzenie(n-2);
}

int main()
{
    cin>>x;
    cout<<sprawdzenie(x)<<endl;
}