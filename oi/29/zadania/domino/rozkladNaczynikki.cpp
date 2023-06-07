#include <bits/stdc++.h>
using namespace std;

vector<long long> dp(105,-1);

long long sprawdzenie(long long n)
{
    if(n==1)return 1;
    if(n==2)return 2;

    if(dp[n]!=-1) return dp[n];
    else return dp[n]=sprawdzenie(n-1)+sprawdzenie(n-2);
}


int main()
{
    long long liczba;
    cin>>liczba;
    for(int i=2;liczba>1;)
    {
        if(liczba%i==0)
        {
            printf("%lld %d\n",liczba,i);
            liczba/=i;
        }
        else i++;
    }
    cout<<"1\n";
}