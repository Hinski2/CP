#include <bits/stdc++.h>
using namespace std;

int amount, ile_monet;
int dp[1005];

vector<int>coins;

void dodaj(int suma, int idx)
{
    for(int i = idx; i < coins.size(); i++)
    {
        dp[suma + coins[i]]++;
        if(suma + coins[i] <= amount) dodaj(suma + coins[i], i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>amount>>ile_monet;

    for(int i = 1; i <= ile_monet; i++)
    {
        int x;
        cin>>x;
        coins.push_back(x);
    }

    dodaj(0, 0);

    cout<<dp[amount]<<"\n";
}