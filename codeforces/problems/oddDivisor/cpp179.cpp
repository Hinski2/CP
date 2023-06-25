#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mak = 1e14;

int t;
vector<ll>liczby;

void liczenie()
{
    ll x;
    cin >> x;

    for(auto u: liczby)
    {
        if(x == u)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

void wyznaczanie_liczb()
{
    for(ll i = 2; i < mak; i *= 2)
    {
        liczby.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

    //preprocesing
    wyznaczanie_liczb();

    //wczytywanie
    cin >> t;
    while(t--)
    {
        liczenie();
    }
}
