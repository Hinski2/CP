#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mak = 2e5 + 15;
const int mod = 10000;

int n, licznik;
ll silnia[mak], ans = 1;
bool mniejszy = true;

unordered_map<int, int>mapa;


void wyznaczanie_silni()
{
    silnia[1] = 1;
    for(ll i = 2; i < mak; i++)
    {
        silnia[i] = (silnia[i - 1] * i) % mod;
    }
}

void wyznaczanie()
{
    for(auto u: mapa)
    {
        ll x = silnia[u.second];

        ans = ans * x;
        if(ans >= 1000) mniejszy = false;
        ans = ans % mod;
    }

    if(licznik > 1) ans = (ans * 2) % mod;
}

void wypisanie()
{
    if(!mniejszy)
    {
        if(ans < 10)
        {
            cout << "000" << ans << "\n";
        }
        else if(ans < 100)
        {
            cout << "00" << ans << "\n";
        }
        else if(ans < 1000)
        {
            cout << "0" << ans << "\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
    else
    {
        cout << ans << "\n";
    }

}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //preprocesing
    wyznaczanie_silni();

    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if(mapa[x] == 0) licznik++;
        mapa[x]++;
    }

    //liczenie
    wyznaczanie();

    //wypisywanie wyniku
    wypisanie();
}