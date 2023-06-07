#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 17;

int tree[base << 1];
int dp[base << 1][21];

void oblicz_dp(int v, int k, int poziom)
{
    if(k == 0) return;              //sprawdzenie czy moge zabrać karety 

    dp[v][1] = tree[v];                //ustawnie dp
    if(poziom == 1) return;         //jeśli to nie najniższy poziom

    //obliczenie wartosci dla synów
    oblicz_dp(v * 2, k - 1, poziom - 1);    
    oblicz_dp(v * 2 + 1, k - 1, poziom - 1);

    for(int i = 2; i <= k; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[v][i] = max(dp[v][i], dp[v * 2][j] + dp[v * 2 + 1][i - j - 1] + tree[v]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    int liczba_pieter, karty_do_zabrania;
    cin >> liczba_pieter >> karty_do_zabrania;
    for(int i = 1; i < (1 << liczba_pieter); i++)
    {
        int a, b;
        cin >> a >> b;
        tree[i] = a + b;
    }

    //liczenie
    karty_do_zabrania /= 2;
    oblicz_dp(1, karty_do_zabrania, liczba_pieter);

    //wypisanie wyniku
    cout << dp[1][karty_do_zabrania] << "\n";
}