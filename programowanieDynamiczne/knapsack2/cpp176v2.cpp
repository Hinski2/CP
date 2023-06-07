#include <bits/stdc++.h>
using namespace std;

const int mak = 1e4 + 15;

int n, pojemnosc;
int waga[mak], wartosc[mak];
long long dp[mak];

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> pojemnosc;
    for(int i = 1; i <= n; i++)
    {
        cin >> waga[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> wartosc[i];
    }

    //liczenie
    for(int i = 1; i <= n; i++)
    {
        for(int j = pojemnosc; j >= waga[i]; j--)
        {
            dp[j] = max(dp[j], wartosc[i] + dp[j - waga[i]]);
        }
    }

    cout << dp[pojemnosc] << "\n";
}