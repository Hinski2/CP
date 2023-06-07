#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mak = 1e6 + 5;
const int mod = 1e9 + 33;

int n;
bool odwiedzony[mak];

vector<pair<int, int>>pierwsze;

void wyznaczanie()
{
    for(ll i = 2; i <= sqrt(n); i++)
    {
        if(!odwiedzony[i]) pierwsze.push_back({i, 1});
        for(ll j = i * i; j < mak; j += i)
        {
            odwiedzony[j] = true;
        }
    }
}

void liczenie()
{
    for(int i = 0; i < pierwsze.size(); i++)
    {
        ll v = pierwsze[i].first;
        int ile = 1;

        ll liczba = v;
        while(liczba * v <= n)
        {
            ile++;
            liczba *= v;
        }

        pierwsze[i].second = ile;
    }

    ll wynik = 1;
    for(auto u: pierwsze)
    {
        wynik = 1LL * (wynik * u.second) % mod;
    }

    cout << wynik << "\n";
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n;

    //liczenie
    wyznaczanie();
    liczenie();
}